#include "include/queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue_create(const int size) {
  if (size <= 0) return NULL;

  Queue *q = malloc(sizeof(Queue));
  if (q == NULL) return NULL;

  q->data = (int *) malloc(sizeof(int) * size);
  if (q->data == NULL) {
    free(q);
    return NULL;
  }

  q->size = size;
  q->front = 0;
  q->rear = 0;
  q->count = 0;

  return q;
}

int queue_is_full(const Queue *q) {
  return q->count == q->size;
}

int queue_is_empty(const Queue *q) {
  return q->count == 0;
}

void enqueue(Queue *q, const int item) {
  if (queue_is_full(q)) {
    printf("Queue Error: Full\n");
    return;
  }
  // 현재 rear에 데이터 삽입
  q->data[q->rear] = item;
  // 나머지 연산자로 원형 큐 구현
  q->rear = (q->rear + 1) % q->size;
  q->count++;
}

int dequeue(Queue *q) {
  if (queue_is_empty(q)) {
    printf("Queue Error: Empty\n");
    return -1;
  }
  const int item = q->data[q->front];
  // 나머지 연산자로 원형 큐 구현
  q->front = (q->front + 1) % q->size;
  q->count--;
  return item;
}

int queue_peek(const Queue *q) {
  if (queue_is_empty(q)) {
    printf("Queue Error: Empty\n");
    return -1;
  }
  return q->data[q->front];
}

void queue_destroy(Queue *q) {
  if (q != NULL) {
    free(q->data);
    free(q);
  }
}
