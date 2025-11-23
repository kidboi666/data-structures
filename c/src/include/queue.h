#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
  int *data;
  int size;
  int front;
  int rear;
  int count;
} Queue;

Queue *queue_create(int size);
int queue_is_full(const Queue *q);
int queue_is_empty(const Queue *q);
void queue_add(Queue *q, int item);
int queue_remove(Queue *q);
int queue_peek(const Queue *q);
void queue_destroy(Queue *q);

#endif //QUEUE_H
