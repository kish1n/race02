#include "../inc/header.h"

int check_points(int **array, int rows, int cols, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= cols || y1 < 0 || y1 >= rows ||
        x2 < 0 || x2 >= cols || y2 < 0 || y2 >= rows) {
        return 2;
    }
    if (array[y1][x1] == 1 && array[y2][x2] == 1) {
        return 0;
    }
    if (array[y1][x1] == 0 || array[y2][x2] == 0) {
        return 1;
    }
    return -1;
}
