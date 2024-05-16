#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p =
		(ListNode*)malloc(sizeof(ListNode));
	p->data = value;					
	p->link = head;		
	head = p;	
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	
	p->data = value;		
	p->link = pre->link;		
	pre->link = p;			
	return head;			
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	
	head = removed->link;	
	free(removed);	
	return head;		
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);		
	return head;			
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link) printf("%d -> ", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	ListNode* u;
	int choice,a,b;
	
	while (1) {
		printf("0. 프로그램 종료\n");
		printf("1. 숫자를 위치에 삽입\n");
		printf("2. 위치에서 숫자 삭제\n");
		printf("3. 리스트 출력\n");

		printf("선택하세요 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			exit(1);
		case 1:
			printf("삽입 할 숫자와 위치를 입력하세요 : ");
			scanf("%d %d", &a, &b);
			if (b == 0) {
				head = insert_first(head, a);
				printf("\n 삽입 시 링크를 따라 이동한 횟수 : 1\n\n");
			}
			else {
				u = head;
				for (int i = 0; i < b-2; i++) {
					u = u->link;
				}
				head = insert(head, u, a);
				printf("\n 삽입 시 링크를 따라 이동한 횟수 : %d\n\n", b);
			}			
			break;
		case 2:
			printf("삭제 할 위치를 입력하세요 : ");
			scanf("%d", &b);
			if (b == 0) {
				head = delete_first(head);
				printf("\n 삭제 시 링크를 따라 이동한 횟수 : 1\n\n");
			}
			else {
				u = head;
				for (int i = 0; i < b - 1; i++) {
					u = u->link;
				}
				head = delete(head, u);
				printf("\n 삭제 시 링크를 따라 이동한 횟수 : %d\n\n", b);
			}
			break;
		case 3:
			printf("\n");
			print_list(head);
			printf("\n");
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
	
	return 0;
}