#include "../inc/header.h"

void queue_init(Queue *queue) {
    queue->capacity = MAX_QUEUE_SIZE;
    queue->size = 0;
    queue->points = malloc(queue->capacity * 8);
}
