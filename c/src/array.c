#include <stdio.h>
#include <stdlib.h>
#include "include/array.h"

/**
 *
 * @param size 배열의 길이
 * @return IntArray 구조체 포인터
 *
 * 주어진 크기(size)로 IntArray 구조체를 생성하고 초기화합니다.
 */
IntArray *array_create(int size) {
  // 배열 생성 함수
  // 크기가 0 이하거나 음수인 배열은 생성할 수 없음
  if (size <= 0) return NULL;

  // 구조체 메모리 할당
  IntArray *arr = malloc(sizeof(IntArray));
  // 할당할 메모리 영역이 없을 경우 NULL 반환
  if (arr == NULL) return NULL;

  // 배열 메모리 할당 (정수 사이즈 * 배열 크기)
  arr->data = (int *) malloc(sizeof(int) * size);
  // 할당할 메모리 영역이 없을 경우 NULL 반환
  if (arr->data == NULL) {
    free(arr); // IntArray 구조체 해제
    return NULL;
  }

  // 배열 크기 메모리 할당
  arr->size = size;

  // 배열 0으로 초기화
  for (int i = 0; i < size; i++) {
    arr->data[i] = 0;
  }

  // 생성한 배열 포인터 반환
  return arr;
}

/**
 *
 * @param arr IntArray 구조체 포인터
 * @param index 값을 설정할 배열의 인덱스
 * @param value 설정할 값
 *
 * 주어진 인덱스에 값을 설정합니다. 인덱스가 유효하지 않으면 오류 메시지를 출력합니다.
 */
void array_set(IntArray *arr, int index, int value) {
  if (arr != NULL && index >= 0 && index < arr->size) {
    arr->data[index] = value;
  } else {
    printf("Array Error: Index out of bounds\n");
  }
}

/**
 *
 * @param arr IntArray 구조체 포인터
 * @param index 가져올 값의 인덱스
 * @return int 값
 *
 * 주어진 인덱스에 해당하는 값을 가져옵니다. 인덱스가 유효하지 않으면 오류 메시지를 출력합니다.
 */
int array_get(IntArray *arr, int index) {
  // 배열 포인터가 할당되어 있고, 인덱스가 0이상의 정수이고, 배열 크기보다 작을 경우
  if (arr != NULL && index >= 0 && index < arr->size) {
    // 해당 인덱스의 값을 반환
    return arr->data[index];
  }
  printf("Array Error: Invalid access\n");
  return -1;
}

/**
 *
 * @param arr IntArray 구조체 포인터
 *
 * IntArray 구조체를 해제합니다.
 */
void array_destroy(IntArray *arr) {
  if (arr != NULL) {
    free(arr->data); // 내부 데이터 해제
    free(arr); // 구조체 해제
  }
}

