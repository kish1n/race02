#include "../inc/header.h"

void queue_enqueue(Queue *queue, Point p) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->points[queue->size++] = p;
}
