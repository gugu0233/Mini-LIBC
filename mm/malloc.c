// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	int *plen;
    int len = size + sizeof( size );

    plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    *plen = len;

    return (void*)(&plen[1]);
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;

    if (nmemb != 0 && total_size / nmemb != size) {
        return NULL;
    }

    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	int *plen = (int*)ptr;
    int len;

    plen--;
    len = *plen;

    munmap((void*)plen, len);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if (new_ptr) {
        memcpy(new_ptr, ptr, size);
    }

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if(nmemb == 0 )
		return NULL;

	if(size == 0)
		return NULL;

	size_t total_size;

	if(__builtin_mul_overflow(nmemb, size, &total_size)){
		return NULL;
	}
	void *new_ptr = realloc(ptr, total_size);
	return new_ptr;
}
