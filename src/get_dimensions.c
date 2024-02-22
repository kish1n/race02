#include "../inc/header.h"

void get_dimensions(const char *filename, int *rows, int *cols) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("Error opening file");
        exit(1);
    }

    char buffer;
    int temp_cols = 0;
    *rows = 0;
    *cols = 0;
    bool first_line = true;

    while (read(fd, &buffer, 1) > 0) {
        if (buffer == '\n') {
            if (first_line) {
                *cols = temp_cols;
                first_line = false;
            }
            (*rows)++;
            temp_cols = 0;
        } else if (buffer != ',' && buffer != '\r') {
            temp_cols++;
        }
    }

    close(fd);

    if (temp_cols > 0) { // Если файл не заканчивается символом новой строки
        (*rows)++;
    }
}
