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
	//ã���� 1 ������ 0
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
		printf("1. ����Ʈ �������� ���� �߰�\n");
		printf("2. ����Ʈ�� �ִ� ���� ����\n");
		printf("3. ������ ���� ��� ���\n");
		printf("4. ����\n");
		printf("�޴��� �����ϼ���.\n");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			//�������� ���ο� ���� �߰�
			printf("�߰��� ������ �Է��ϼ��� : ");
			scanf("%s", arr);
			if (search_list(head, arr) == 0) {
				u = head;
				for (int i = 0; i < size - 1; i++) {
					u = u->link;
				}
				insert(head, u, arr);
			}
			else printf("�Է� ���� ������ �̹� ����Ʈ�� �ֽ��ϴ�.\n\n");
			break;
		case 2:
			//����Ʈ�� �ִ� ���� ����
			printf("������ ������ �Է��ϼ��� : ");
			scanf("%s", arr);
			a = search_list(head, arr);
			if (a==0) printf("�Է¹��� ������ ����Ʈ�� �����ϴ�.\n\n");
			else {
				printf("%s �� ����Ʈ���� �����Ǿ����ϴ�.\n",arr);
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
			//������ ���� ��� ���
			printf("������ ������ ����Դϴ� : ");
			print_list(deleted);
			printf("\n");
			break;
		case 4:
			exit(1);
		default:
			printf("�߸��� �޴� �Է��Դϴ�. �ٽ� �������ּ���.\n\n");
			break;
		}
		
	}

	return 0;
 }