#include "../inc/header.h"

bool mx_isnumber(const char *str) {
    // Пустая строка или NULL не являются числом
    if (str == NULL || *str == '\0') {
        return false;
    }

    // Проверяем каждый символ строки
    while (*str != '\0') {
        if (!mx_isdigit((unsigned char)*str)) {
            return false;
        }
        str++;
    }

    return true;
}
