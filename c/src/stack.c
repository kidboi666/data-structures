#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define IS_NUMBER(symbol) symbol != '+' && symbol != '-' && symbol != '/' && symbol != '*'

int stack[MAX_SIZE];
int top = -1;


void push(const int data) {
  if (top >= MAX_SIZE - 1) {
    printf("Error: Stack Overflow \n");
    return;
  }
  stack[++top] = data;
}

int pop() {
  if (top == -1) {
    printf("Error: Stack is Empty \n");
    return -1;
  }
  return stack[top--];
}

int peek() {
  if (top == -1) {
    printf("Error: Stack is Empty \n");
    return -1;
  }
  return stack[top];
}

int evalPostfix(const char *exp) {
  int oper1, oper2, value, i = 0;
  int length = strlen(exp);
  char symbol;
  top = -1;
  for (i = 0; i < length; i++) {
    symbol = exp[i];
    if (IS_NUMBER(symbol)) {
      value = symbol - '0';
      push(value);
    } else {
      oper2 = pop();
      oper1 = pop();
      switch (symbol) {
        case '+': push(oper1 + oper2);
          break;
        case '-': push(oper1 - oper2);
          break;
        case '*': push(oper1 * oper2);
          break;
        case '/': push(oper1 / oper2);
          break;
        default: ;
      }
    }
  }
  return pop();
}
