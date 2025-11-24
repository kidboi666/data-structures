#include "include/singly_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 빈 연결 리스트를 생성합니다.
 *
 * @return 새로 생성된 LinkedList 구조체에 대한 포인터.
 *         메모리 할당이 실패하면 NULL을 반환합니다.
 */
SinglyList *singly_list_create() {
  // LinkedList 구조체에 대한 메모리를 동적으로 할당합니다.
  // 이 메모리는 힙에 할당되며, 연결 리스트의 생명 주기 동안 유지됩니다.
  // 할당에 실패하면 NULL을 반환하여 오류를 알립니다.
  // 할당된 LinkedList 구조체의 head 멤버를 NULL로 초기화하여 빈 리스트 상태를 나타냅니다.
  SinglyList *l = (SinglyList *) malloc(sizeof(SinglyList));
  if (l == NULL) {
    printf("Singly List Error: Failed to allocate memory\n");
    return NULL;
  }

  l->head = NULL;
  return l;
}

/**
 * @brief 연결 리스트의 끝에 새 노드를 추가합니다.
 *
 * 이 함수는 주어진 데이터를 포함하는 새 노드를 생성하고
 * 연결 리스트의 마지막에 추가합니다.
 *
 * @param l 노드를 추가할 LinkedList 구조체에 대한 포인터.
 * @param data 새 노드에 저장할 정수 데이터.
 */
void singly_list_add(SinglyList *l, const int data) {
  ListNode *new_node;
  new_node = (ListNode *) malloc(sizeof(ListNode));
  new_node->data = data;
  new_node->link = NULL;

  // 리스트가 비어있는 경우
  if (l->head == NULL) {
    l->head = new_node;
    return;
  }

  // 리스트가 비어있지 않은 경우
  ListNode *last_node;
  last_node = l->head;

  // 리스트의 마지막 노드까지 이동
  while (last_node->link != NULL) {
    last_node = last_node->link;
  }

  // 마지막 노드의 다음 노드로 새로운 노드를 연결
  last_node->link = new_node;
}

/**
 * @brief 주어진 이전 노드와 현재 노드를 사용하여 연결 리스트에서 노드를 삭제합니다.
 *
 * 이 함수는 `prev` 노드 뒤에 있는 `curr` 노드를 연결 리스트에서 제거합니다.
 * `curr` 노드의 메모리는 해제됩니다.
 * @param l 연결 리스트에 대한 포인터.
 * @param prev 삭제할 노드(`curr`)의 이전 노드에 대한 포인터.
 * @param curr 삭제할 노드에 대한 포인터.
 */
void singly_list_delete_node(SinglyList *l, ListNode *prev, ListNode *curr) {
  prev->link = curr->link;
  free(curr);
}

/**
 * @brief 연결 리스트의 마지막 노드를 삭제합니다.
 *
 * @param l 노드를 삭제할 LinkedList 구조체에 대한 포인터.
 */
void singly_list_delete_last(SinglyList *l) {
  if (l == NULL || l->head == NULL) return;

  // 리스트에 노드가 하나만 있는 경우
  if (l->head->link == NULL) {
    free(l->head);
    l->head = NULL;
    return;
  }

  // 리스트에 노드가 여러개 있는 경우
  ListNode *prev = l->head;

  // 리스트의 마지막 노드까지 이동
  while (prev->link->link != NULL) {
    prev = prev->link;
  }

  free(prev->link);
  prev->link = NULL;
}

/**
 * @brief 주어진 데이터를 가진 노드를 연결 리스트에서 찾아 삭제합니다.
 *
 * 이 함수는 연결 리스트를 순회하며 `data`와 일치하는 값을 가진 첫 번째 노드를 찾습니다.
 * 해당 노드가 발견되면 리스트에서 제거하고 메모리를 해제합니다.
 *
 * @param list 노드를 삭제할 LinkedList 구조체에 대한 포인터.
 * @param data 삭제할 노드가 가지고 있는 정수 데이터.
 */
void singly_list_find_and_delete(SinglyList *list, const int data) {
  if (list == NULL || list->head == NULL) {
    printf("Singly List Error: Empty\n");
    return;
  }

  ListNode *curr = list->head;
  ListNode *prev = NULL;

  // 리스트에 노드가 하나만 있는 경우
  if (curr->data == data) {
    list->head = curr->link;
    free(curr);
    return;
  }

  // 리스트에 노드가 여러개 있는 경우
  while (curr != NULL && curr->data != data) {
    prev = curr;
    curr = curr->link;
  }

  // 값을 찾지 못한 경우
  if (curr == NULL) {
    printf("Singly List Error: Not Found\n");
    return;
  }

  // 값을 찾은 경우
  prev->link = curr->link;
  free(curr);
}

/**
 * @brief 연결 리스트가 사용하는 모든 메모리를 해제합니다.
 *
 * 이 함수는 연결 리스트의 모든 노드를 순회하며 각 노드에 할당된 메모리를 해제합니다.
 * 마지막으로 LinkedList 구조체 자체에 할당된 메모리도 해제합니다.
 *
 * @param l 해제할 LinkedList 구조체에 대한 포인터.
 */
void singly_list_destroy(SinglyList *l) {
  if (l == NULL) return;

  ListNode *current = l->head;
  ListNode *next;
  while (current != NULL) {
    next = current->link;
    free(current);
    current = next;
  }
  free(l);
}
