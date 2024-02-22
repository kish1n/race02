#include "../inc/header.h"

int **read_map_from_file(const char *filename) {
    int file_size = get_file_size(filename);
    char *content = mx_strnew(file_size);


    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    char buffer;
    int len = 0;
    while (read(fd, &buffer, 1) > 0) {
        if (buffer != ',') {
            content[len++] = buffer;
        }
    }



    close(fd);
    int rows = 0, cols = 0, temp_cols = 0;
    bool new_row = true;
    for (int i = 0; i < len; ++i) {
        if (content[i] == '\n') {
            if (new_row) {
                mx_printerr("error\n");
                exit(1);
            }
            if (cols == 0) cols = temp_cols;
            if (temp_cols != cols) {
                mx_printerr("map error\n");
                exit(1);
            }
            temp_cols = 0;
            new_row = true;
        } else {
            if (content[i] != '#' && content[i] != '.') {
                mx_printerr("map error\n");
                exit(1);
            }
            temp_cols++;
            new_row = false;
        }
        cols = temp_cols;
        rows++;
    }

    if (temp_cols != cols) {
        mx_printerr("map error\n");
        exit(1);
    }

    int **map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        map[i] = (int *)malloc(cols * sizeof(int));
    }

    int row = 0, col = 0;
    for (int i = 0; i < len; ++i) {
        if (content[i] == '\n') {
            row++;
            col = 0;
        } else {
            map[row][col++] = (content[i] == '.') ? 1 : 0;
        }
    }

    free(content);
    return map;
}
