#include "../inc/header.h"

Point queue_dequeue(Queue *queue) {
    Point p = queue->points[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->points[i] = queue->points[i + 1];
    }
    queue->size--;
    return p;
}
