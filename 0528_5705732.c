#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

ListNode* insert_last(ListNode* tail, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
	return tail; 
}

ListNode* delete_first(ListNode* tail)
{
	ListNode* removed;
	if (tail == NULL) return NULL;
	removed = tail->link;
	tail->link = removed->link;
	free(removed);
	return tail;
}

ListNode* delete_last(ListNode* tail)
{
	ListNode* removed;
	if (tail == NULL) return NULL;
	removed = tail;
	
	while (tail->link != removed) {
		tail = tail->link;
	}
	tail->link = removed->link;

	free(removed);
	return tail;
}

void print_list(ListNode* tail)
{
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != tail);
	
	printf("%d (head)", p->data);
}

int main(void)
{
	ListNode* tail = NULL;

	int choice,a;
	
	while (1) {
		printf("�޴� :\n");
		printf("1: ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2: ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3: ����Ʈ ó�� ��� ����\n");
		printf("4: ����Ʈ ������ ��� ����\n");
		printf("5: ����Ʈ ����Ʈ\n");
		printf("6: ����\n");
		printf("�޴��� �����ϼ��� : ");		
		
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			printf("�߰� �� ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &a);
			printf("\n");
			tail = insert_first(tail, a);
			break;
		case 2:
			printf("�߰� �� ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &a);
			printf("\n");
			tail = insert_last(tail, a);
			break;
		case 3:
			tail = delete_first(tail);
			break;
		case 4:
			tail = delete_last(tail);
			break;
		case 5:
			print_list(tail);
			printf("\n\n");
			break;
		case 6:
			exit(1);
		}
	}



	return 0;
}
