#include <stdio.h>

#define ARRAY_SIZE 5
#define IS_VALIDATE_FROM_SIZE(i) i >= 0 && i < ARRAY_SIZE

void create(const int n) {
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
}

int retrieve(const int *a, const int i) {
  if (IS_VALIDATE_FROM_SIZE(i)) return a[i];
  printf("Error \n");
  return -1;
}

void store(int *a, const int i, const int e) {
  if (i >= 0 && i < ARRAY_SIZE) a[i] = e;
  printf("Error \n");
}
