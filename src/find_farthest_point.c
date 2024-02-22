#include "../inc/header.h"

int find_farthest_point(int **array, int rows, int cols, Point start, Point *farthest) {
    int steps[rows][cols];
    memset(steps, -1, sizeof(steps)); // Инициализируем массив шагов значением -1

    Queue queue;
    queue_init(&queue);
    queue_enqueue(&queue, start);
    steps[start.y][start.x] = 0; // Начальное количество шагов равно 0

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int max_dist = -1;

    while (!queue_is_empty(&queue)) {
        Point p = queue_dequeue(&queue);
        for (int j = 0; j < 4; j++) {
            int nx = p.x + dx[j];
            int ny = p.y + dy[j];

            if (nx >= 0 && ny >= 0 && nx < cols && ny < rows && array[ny][nx] == 1 && steps[ny][nx] == -1) {
                steps[ny][nx] = steps[p.y][p.x] + 1; // Увеличиваем количество шагов
                queue_enqueue(&queue, (Point){nx, ny});

                if (steps[ny][nx] > max_dist) {
                    max_dist = steps[ny][nx];
                    *farthest = (Point){nx, ny};
                }
            }
        }
    }

    queue_free(&queue);
    return max_dist;
}
