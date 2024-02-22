#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 10000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
    int capacity;
} Queue;

bool mx_isspace(char c);
int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
int mx_abs(int n);
bool mx_isnumber(const char *str);

int get_file_size(const char *filename);
void get_dimensions(const char *filename, int *rows, int *cols);
int **read_map_from_file(const char *filename);
int check_points(int **array, int rows, int cols, int x1, int y1, int x2, int y2);
void queue_init(Queue *queue);
void queue_enqueue(Queue *queue, Point point);
Point queue_dequeue(Queue *queue);
bool queue_is_empty(Queue *queue);
void queue_free(Queue *queue);
int find_shortest_path(int **array, int rows, int cols, Point start, Point end);
int find_farthest_point(int **array, int rows, int cols, Point start, Point *farthest);

#endif
