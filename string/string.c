// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
	char *ptr = destination;
    while (*source != '\0')
    {
        *ptr = *source;
        ptr++;
        source++;
    }
    *ptr = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
	char *ptr = destination;
	while(*source != '\0' && len > 0) {
		*ptr = *source;
		ptr++;
		source++;
		len--;
	}
	while(len > 0) {
		*ptr = '\0';
		ptr++;
		len--;
	}
	return destination;
}

char *strcat(char *destination, const char *source) {
	size_t i, j;
    for (i = 0; destination[i] != '\0'; i++)
        ;
    for (j = 0; source[j] != '\0'; j++)
        destination[i+j] = source[j];
    destination[i+j] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
	char* ptr = destination + strlen(destination);
    while (*source != '\0' && len--) {
        *ptr++ = *source++;
    }
    *ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2) {
	while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int strncmp(const char *str1, const char *str2, size_t len) {
	if(len == 0)
		return 0;
	while(len-- != 0 )
	{
		if(*str1 != *str2)
			return (*(unsigned char *) str1 - *(unsigned char *) str2);
		if(*str1 == '\0')
			break;
		str1++;
		str2++;
	}
	return 0;
}

size_t strlen(const char *str) {
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
	while (*str != c && *str != '\0') {
	str++;
	}
	if(*str == c) {
      return (char *)str;
	} else 	{
		return NULL;
	}
}

char *strrchr(const char *str, int c) {
	const char* last = NULL;
	while (*str != '\0') {
		if(*str == c)
			last = str;
		str++;
	}
	if(last != NULL)
		return (char*)last;
	return NULL;
}

char *strstr(const char *haystack, const char *needle) {
	while(*haystack) {
		const char* h = haystack;
		const char* n = needle;
		for (h = haystack, n = needle; *h && *n && (*h == *n); h++, n++)
			continue;
		if (*n == '\0')
			return (char*)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
	size_t haystack_len = strlen(haystack);
	size_t needle_len = strlen(needle);
	if(needle_len > haystack_len)
		return NULL;
	int i;
	for(i = haystack_len-needle_len; i >= 0; i--)
	if(strncmp(haystack+i, needle, needle_len) == 0)
		return(char*)(haystack +i);
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
	char *dest = (char *)destination;
    const char *src = (const char *)source;
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
	char *pDest = (char *)destination;
    const char *pSrc = (const char *)source;

    if (pDest < pSrc) {
        for (size_t i = 0; i < num; i++) {
            pDest[i] = pSrc[i];
        }
    } else if (pDest > pSrc) {
        for (size_t i = num; i > 0; i--) {
            pDest[i - 1] = pSrc[i - 1];
        }
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num) {
	unsigned char *p = (unsigned char *)source;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }
	return source;
}
