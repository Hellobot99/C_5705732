#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef int element; 
int asd;

typedef struct {
	element array[MAX_LIST_SIZE]; 
	int size;
} ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	if (L->size == 0)printf("리스트가 비어있습니다.\n");
	for (i = 0; i < L->size; i++)
		printf("%d -> ", L->array[i]);
	printf("NULL\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
	asd = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i],asd++;
		L->array[pos] = item;
		L->size++;
	}
}

void insert_first(ArrayListType* L, element item)
{
	insert(L, 0, item);
}

element delete(ArrayListType* L, int pos)
{
	asd = 0;
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1],asd++;
	L->size--;
	return item;
}

int main() {

	ArrayListType list;
	int a,b,choice;
	init(&list);
	while (1) {
		printf("0. 프로그램 종료\n");
		printf("1. 리스트 추가\n");
		printf("2. 리스트 삭제\n");
		printf("3. 리스트 출력\n");

		printf("메뉴를 선택하세요 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			exit(1);
		case 1:
			printf("숫자와 위치를 입력해주세요 : ");
			scanf("%d %d", &a, &b);
			insert(&list, b, a);
			printf("\n 데이터 이동횟수는 : %d 회 입니다.\n\n", asd);
			break;
		case 2:
			printf("삭제할 위치를 입력해주세요 : ");
			scanf("%d", &a);
			delete(&list, a);
			printf("\n 데이터 이동횟수는 : %d 회 입니다.\n\n", asd);
			break;
		case 3:
			print_list(&list);
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}

	return 0;

}