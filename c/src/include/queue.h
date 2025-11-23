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
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int queue_peek(const Queue *q);
void queue_destroy(Queue *q);

#endif //QUEUE_H
