#include "../inc/header.h"

int get_file_size(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error\n");
        exit(1);
    }

    char buffer;
    int size = 0;
    while (read(fd, &buffer, 1) > 0) {
        if (buffer != ',') {
            size++;
        }
    }

    close(fd);
    return size;
}
