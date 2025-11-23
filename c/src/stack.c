#include <stdio.h>
#include "include/stack.h"

void stack_init(Stack *s) {
  s->top = -1;
}

int stack_is_empty(const Stack *s) {
  return s->top == -1;
}

int stack_is_full(const Stack *s) {
  return s->top == MAX_STACK_SIZE - 1;
}

void stack_push(Stack *s, const int value) {
  if (s->top >= MAX_STACK_SIZE - 1) {
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
