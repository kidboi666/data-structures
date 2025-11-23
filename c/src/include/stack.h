#ifndef C_STACK_H
#define C_STACK_H
#define MAX_STACK_SIZE 100000

typedef struct {
  int data[MAX_STACK_SIZE];
  int top;
} Stack;

void stack_init(Stack *s);
int stack_is_empty(const Stack *s);
int stack_is_full(const Stack *s);
void stack_push(Stack *s, int value);
int stack_pop(Stack *s);
int stack_peek(const Stack *s);

#endif //C_STACK_H
