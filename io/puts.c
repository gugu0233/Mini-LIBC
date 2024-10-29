#include <string.h>
#include <stdio.h>
#include <unistd.h>

int puts(const char *str) {
    int len = 0;
    while (str[len] != '\0') {  // calculez lungimea sirului
        len++;
    }
    int i;
    for (i = 0; i < len; i++) {  // afisez fiecare caracter
        if (write(1, &str[i], 1) == -1) {
            return -1;
        }
    }
    if (write(1, "\n", 1) == -1) {  // afisez caracterul newline la final
        return -1;
    }
    return 0;
}
