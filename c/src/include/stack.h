#ifndef C_STACK_H
#define C_STACK_H

typedef struct {
  int *data;
  int size;
  int top;
} Stack;

Stack *stack_create(int size);
int stack_is_empty(const Stack *s);
int stack_is_full(const Stack *s);
void stack_push(Stack *s, int value);
int stack_pop(Stack *s);
int stack_peek(const Stack *s);

#endif //C_STACK_H
