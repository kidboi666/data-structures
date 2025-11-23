//
// Created by leejinwook on 25. 11. 23..
//

#ifndef C_STACK_H
#define C_STACK_H

typedef struct {
  int items[100];
  int top;
} Stack;

void init_stack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);

#endif //C_STACK_H
