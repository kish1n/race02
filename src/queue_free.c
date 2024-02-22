#include "../inc/header.h"

void queue_free(Queue *queue) {
    free(queue->points);
}
