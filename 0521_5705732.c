#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
int size;
int size_deleted=0;

typedef struct listNode {
	element data[20];
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value[])
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->data, value);
	p->link = head;
	head = p;
	size++;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value[])
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->data, value);
	p->link = pre->link;
	pre->link = p;
	size++;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	size--;
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	size--;
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link) printf("%s -> ", p->data);
	printf("NULL \n");
}

element search_list(ListNode* head, element abc[])
{
	//찾으면 1 없으면 0
	ListNode* p = head;
	int count = 1;
	while (p != NULL) {
		if (strcmp(p->data, abc) == 0) return count;
		p = p->link;
		count++;
	}
	return 0;
}

main()
 {
	ListNode* head = NULL;
	ListNode* u;
	ListNode* deleted = NULL;
	size = 0;
	int a;
	

	int choice;
	char arr[20];
	strcpy(arr, "Peach");
	head = insert_first(head, arr);
	strcpy(arr, "Banana");
	head = insert_first(head, arr);
	strcpy(arr, "Raspberry");
	head = insert_first(head, arr);
	strcpy(arr, "Guava");
	head = insert_first(head, arr);
	strcpy(arr, "Plum");
	head = insert_first(head, arr);
	strcpy(arr, "Cherry");
	head = insert_first(head, arr);
	strcpy(arr, "Grape");
	head = insert_first(head, arr);	
	strcpy(arr, "Apple");
	head = insert_first(head, arr);	
	strcpy(arr, "Orange");
	head = insert_first(head, arr);	
	strcpy(arr, "Mango");
	head = insert_first(head, arr);
	
	while (1) {
		printf("1. 리스트 마지막에 과일 추가\n");
		printf("2. 리스트에 있는 과일 삭제\n");
		printf("3. 삭제된 과일 목록 출력\n");
		printf("4. 종료\n");
		printf("메뉴를 선택하세요.\n");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			//마지막에 새로운 과일 추가
			printf("추가할 과일을 입력하세요 : ");
			scanf("%s", arr);
			if (search_list(head, arr) == 0) {
				u = head;
				for (int i = 0; i < size - 1; i++) {
					u = u->link;
				}
				insert(head, u, arr);
			}
			else printf("입력 받은 과일은 이미 리스트에 있습니다.\n\n");
			break;
		case 2:
			//리스트에 있는 과일 삭제
			printf("삭제할 과일을 입력하세요 : ");
			scanf("%s", arr);
			a = search_list(head, arr);
			if (a==0) printf("입력받은 과일은 리스트에 없습니다.\n\n");
			else {
				printf("%s 가 리스트에서 삭제되었습니다.\n",arr);
				u = head;
				for (int i = 0; i < a - 2; i++) {
					u = u->link;
				}

				deleted = insert_first(deleted, u->link->data);
				size--;

				u = head;				
				for (int i = 0; i < a - 2; i++) {
					u = u->link;
				}
				head = delete(head, u);
			}
			break;
		case 3:
			//삭제된 과일 목록 출력
			printf("삭제된 과일의 목록입니다 : ");
			print_list(deleted);
			printf("\n");
			break;
		case 4:
			exit(1);
		default:
			printf("잘못된 메뉴 입력입니다. 다시 선택해주세요.\n\n");
			break;
		}
		
	}

	return 0;
 }