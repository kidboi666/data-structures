#ifndef C_ARRAY_H
#define C_ARRAY_H

typedef struct {
  int *data;
  int size;
} IntArray;

IntArray *array_create(int size);
void array_set(IntArray *arr, int index, int value);
int array_get(IntArray *arr, int index);
void array_destroy(IntArray *arr);

#endif //C_ARRAY_H
