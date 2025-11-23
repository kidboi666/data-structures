#include "include/stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create(const int size) {
  if (size <= 0) return NULL;

  Stack *s = malloc(sizeof(Stack));
  if (s == NULL) return NULL;

  s->data = (int *) malloc(sizeof(int) * size);
  if (s->data == NULL) {
    free(s);
    return NULL;
  }

  s->size = size;
  s->top = -1;

  return s;
}

int stack_is_empty(const Stack *s) {
  return s->top == -1;
}

int stack_is_full(const Stack *s) {
  return s->top == s->size - 1;
}

void stack_push(Stack *s, const int value) {
  if (stack_is_full(s)) {
    printf("Error: Stack Overflow \n");
    return;
  }
  s->data[++s->top] = value;
}

int stack_pop(Stack *s) {
  if (stack_is_empty(s)) {
    printf("Stack Error: Empty\n");
    return -1;
  }
  return s->data[s->top--];
}

int stack_peek(const Stack *s) {
  if (stack_is_empty(s)) {
    printf("Stack Error: Empty\n");
    return -1;
  }
  return s->data[s->top];
}

void stack_destroy(Stack *s) {
  if (s != NULL) {
    free(s->data);
    free(s);
  }
}
