#include "../inc/header.h"

int mx_strlen(const char* s) {
    int acc = 0;
    while (*s != '\0'){
        acc++;
        s++;
    }
    return acc;
}

