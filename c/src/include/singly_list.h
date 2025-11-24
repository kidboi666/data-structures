#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

/**
 * 상황: 연결 리스트의 노드는 다음 노드를 가리켜야 한다. 즉, 자기 자신과 똑같은 타입의 포인터가 있어야 함.
 * 문제: typedef로 만든 별칭은 중괄호가 닫히고 나서야 탄생함. 구조체 내부에서는 ListNode라는 별칭이 존재하지 않음.
 * 해결: struct 바로 뒤에 임시 이름인 ListNode를 붙여주어 내부에서도 사용할 수 있게 됨.
 */
typedef struct ListNode {
  int data;
  struct ListNode *link;
} ListNode;

/**
 * 자기 자신을 구조체 내부에서 가리킬 필요가 없을 경우 구조체 태그를 따로 명시할 필요가 없음.
 */
typedef struct {
  ListNode *head;
} SinglyList;

SinglyList *singly_list_create();
void singly_list_add(SinglyList *l, int data);
void singly_list_delete_node(SinglyList *l, ListNode *prev, ListNode *curr);
void singly_list_delete_last(SinglyList *l);
void singly_list_find_and_delete(SinglyList *list, int data);
void singly_list_destroy(SinglyList *l);

#endif //SINGLY_LIST_H
