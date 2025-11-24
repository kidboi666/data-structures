#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct ListNode {
  int data;
  struct ListNode *link;
} ListNode;

typedef struct {
  ListNode *head;
} CircularList;

CircularList *circular_list_create();
void circular_list_add(CircularList *list, int data);
void circular_list_add_middle(const CircularList *list, ListNode *prev, int data);
void circular_list_delete(const CircularList *list, int data);
void circular_list_delete_last(CircularList *list);
void circular_list_find_and_delete(CircularList *list, int data);
void circular_list_destroy(CircularList *list);

#endif //CIRCULAR_LIST_H
