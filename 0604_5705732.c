#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
int size;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
	size++;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
	size--;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<- %d -> ", p->data);
	}
	printf("(head)");
	printf("\n");
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	int choice, a;

	while (1) {
		printf("메뉴 :\n");
		printf("1: 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2: 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3: 리스트 처음 노드 삭제\n");
		printf("4: 리스트 마지막 노드 삭제\n");
		printf("5: 리스트 프린트\n");
		printf("6: 종료\n");
		printf("메뉴를 선택하세요 : ");

		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			printf("추가 할 숫자를 입력하세요 : ");
			scanf("%d", &a);
			dinsert(head, a);
			printf("\n");
			
			break;
		case 2:
			printf("추가 할 숫자를 입력하세요 : ");
			scanf("%d", &a);
			dinsert(head->llink, a);
			printf("\n");
			
			break;
		case 3:
				ddelete(head, head->rlink);
			break;
		case 4:
			ddelete(head, head->llink);
			break;
		case 5:
			print_dlist(head);
			printf("\n\n");
			break;
		case 6:
			exit(1);
		}
	}

	free(head);
	return 0;
}
