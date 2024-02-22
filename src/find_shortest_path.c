#include "../inc/header.h"

int find_shortest_path(int **array, int rows, int cols, Point start, Point end) {
    if (array[start.y][start.x] == 0 || array[end.y][end.x] == 0) {
        return -1;
    }

    bool visited[rows][cols];
    memset(visited, false, sizeof(visited));
    visited[start.y][start.x] = true;

    Queue queue;
    queue_init(&queue);
    queue_enqueue(&queue, start);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int steps = 0;

    while (!queue_is_empty(&queue)) {
        int size = queue.size;
        for (int i = 0; i < size; i++) {
            Point p = queue_dequeue(&queue);
            if (p.x == end.x && p.y == end.y) {
                queue_free(&queue);
                return steps;
            }
            for (int j = 0; j < 4; j++) {
                int nx = p.x + dx[j];
                int ny = p.y + dy[j];
                if (nx >= 0 && ny >= 0 && nx < cols && ny < rows && array[ny][nx] == 1 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    queue_enqueue(&queue, (Point){nx, ny});
                }
            }
        }
        steps++;
    }

    queue_free(&queue);
    return -1;
}
