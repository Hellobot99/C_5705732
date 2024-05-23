#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode { 
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

typedef struct ListType { 
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, element coef, element expon)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {  
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist)
{
	ListNode* p = plist->head;
	while(p){
		printf("%d x^%d", p->coef, p->expon);
		p = p->link;
		if(p!=NULL) printf(" + ");
	}
	printf("\n");
}

int main(void)
{
	ListType* list1, * list2, * list3;
	int num;
	int c, e;

	list1 = create();
	list2 = create();
	list3 = create();

	printf("두개의 다항식을 더하는 프로그램입니다. \n\n");
	printf("첫번째 다항식의 항 개수를 입력해주세요 : ");
	scanf("%d", &num);
	for (int i = 1; i < num+1; i++) {
		printf("%d 번째 항의 coef과 expon를 입력해주세요 : ",i);
 		scanf("%d %d", &c, &e);
		printf("\n");
		insert_last(list1, c, e);
	}
	printf("두번째 다항식의 항 개수를 입력해주세요 : ");
	scanf("%d", &num);
	for (int i = 1; i < num + 1; i++) {
		printf("%d 번째 항의 coef과 expon를 입력해주세요 : ",i);
		scanf("%d %d", &c, &e);
		printf("\n");
		insert_last(list2, c, e);
	}

	poly_add(list1, list2, list3);
	
	printf("두 다항식의 합은 :");
	poly_print(list3);

	free(list1); free(list2); free(list3);

	return 0;
}


