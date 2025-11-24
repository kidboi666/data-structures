#include "include/circular_list.h"
#include <stdio.h>
#include <stdlib.h>

CircularList *circular_list_create() {
  CircularList *list = malloc(sizeof(CircularList));
  if (list == NULL) {
    printf("Circular List Error: Failed to allocate memory\n");
    return NULL;
  }
  list->head = NULL;
  return list;
}

void circular_list_add(CircularList *list, const int data) {
  if (list == NULL) return;

  ListNode *new_node = malloc(sizeof(ListNode));
  if (new_node == NULL) {
    printf("Circular List Error: Failed to allocate memory\n");
    return;
  }
  new_node->data = data;
  new_node->link = NULL;

  // 원형 연결 리스트가 비어있는 경우
  if (list->head == NULL) {
    list->head = new_node;
    new_node->link = new_node;
  }

  // 원형 연결 리스트가 비어있지 않은 경우
  ListNode *temp_node = list->head;

  // temp_node가 마지막 노드가 아니라면
  while (temp_node->link != list->head) {
    // temp_node를 다음 노드로 이동
    temp_node = temp_node->link;
  }
  // 마지막 노드의 다음 노드로 새로운 노드 연결
  temp_node->link = new_node;
  // 새로운 노드의 다음 노드로 원형 연결 리스트의 헤드 노드 연결
  new_node->link = list->head;
}

void circular_list_add_middle(const CircularList *list, ListNode *prev, const int data) {
  if (list == NULL) return;

  ListNode *new_node = malloc(sizeof(ListNode));
  if (new_node == NULL) {
    printf("Circular List Error: Failed to allocate memory\n");
    return;
  }
  new_node->data = data;
  new_node->link = NULL;

  new_node->link = prev->link;
  prev->link = new_node;
}

void circular_list_delete_node(const CircularList *list, ListNode *prev) {
  ListNode *last_node = list->head;
  ListNode *delete_node = prev->link;

  while (last_node->link != list->head) {
    last_node = last_node->link;
  }

  prev->link = delete_node->link;

  if (list->head == delete_node) {
    last_node->link = list->head;
  }

  free(delete_node);
}

void circular_list_delete(const CircularList *list, const int data) {
  if (list == NULL || list->head == NULL) {
    printf("Circular List Error: Empty\n");
  } else {
    ListNode *curr = list->head;
    ListNode *prev = NULL;

    do {
      if (curr->data == data) {
        if (curr->)
          circular_list_delete_node(list, prev);
      } else {
        prev = curr;
        curr = curr->link;
      }
    } while (curr != list->head);
  }
}

