#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    if (mx_isnumber(argv[2]) && mx_isnumber(argv[3]) && mx_isnumber(argv[4]) && mx_isnumber(argv[5])) {
        x1 = mx_atoi(argv[2]);
        y1 = mx_atoi(argv[3]);
        x2 = mx_atoi(argv[4]);
        y2 = mx_atoi(argv[5]);
    } else {
        mx_printerr("error\n");
        return 1;
    }

    int rows = 0, cols = 0;

    get_dimensions(argv[1], &rows, &cols);

    if (rows == 0 || cols == 0) {
        mx_printerr("map does not exist\n");
        return 1;
    }

    int sol = check_points(read_map_from_file(argv[1]), rows, cols, x1, y1, x2, y2);

    if (sol == 1) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(1);
    } else if (sol == 2) {
        mx_printerr("points are out of map range\n");
        exit(1);
    }

    int **map = read_map_from_file(argv[1]);

    int exit = find_shortest_path(map, rows, cols, (Point){x1, y1}, (Point){x2, y2});

    Point farthest;
    find_farthest_point(map, rows, cols, (Point){x1, y1}, (Point *)&farthest);

    int dist = find_shortest_path(map, rows, cols, (Point){x1, y1}, farthest);

    mx_printstr("dist=");
    mx_printint(dist);
    mx_printchar('\n');
    mx_printstr("exit=");
    mx_printint(exit);
    mx_printchar('\n');
    return 0;
}
