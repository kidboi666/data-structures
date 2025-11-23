#include "src/include/array.h"
#include "src/include/stack.h"
#include "src/include/queue.h"
#include <stdio.h>

int main(void) {
  printf("Array Test\n");
  IntArray *arr = array_create(5);
  if (arr != NULL) {
    array_set(arr, 0, 10);
    array_set(arr, 1, 20);
    printf("Array[0]: %d\n", array_get(arr, 0));
    printf("Array[1]: %d\n", array_get(arr, 1));
    array_destroy(arr);
  }

  printf("Stack Test\n");
  Stack *s = stack_create(5);
  if (s != NULL) {
    stack_push(s, 10);
    stack_push(s, 20);
    printf("Stack Pop: %d\n", stack_pop(s));
    printf("Stack Peek: %d\n", stack_peek(s));
    stack_destroy(s);
  }

  printf("Queue Test\n");
  Queue *q = queue_create(5);
  if (q != NULL) {
    queue_is_empty(q);
    queue_add(q, 10);
    queue_add(q, 20);
    printf("Queue Dequeue: %d\n", queue_remove(q));
    printf("Queue Peek: %d\n", queue_peek(q));
    queue_destroy(q);
  }

  printf("All Tests Completed\n");
  return 0;
}
