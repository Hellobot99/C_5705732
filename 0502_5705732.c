#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element  data[MAX_QUEUE_SIZE];
	int  front, rear, size;
} QueueType;

element stack[MAX_QUEUE_SIZE];
int top = -1;

int is_empty_stack()
{
	return(top == -1);
}

int is_full_stack()
{
	return(top == MAX_QUEUE_SIZE - 1);
}

void push(element item)
{
	if (is_full_stack())
	{
		printf("Stack Overflow\n");
		return;
	}
	else stack[++top] = item;
}

element pop()
{
	if (is_empty_stack())
	{
		printf("Stack is empty\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty_stack())
	{
		printf("스택이 비어있습니다.\n");
	}
	else return stack[top];
}

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q)
{
	q->front = 0, q->rear = 0, q->size = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		q->size++;
	}
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		q->size--;
		return q->data[q->front];
	}
}

int main(void)
{
	QueueType queue;
	int choice, result=0,a,b;
	char str[MAX_QUEUE_SIZE+1];
	init_queue(&queue);
	
	while (1) {
		printf("1. 회문 입력\n");
		printf("2. 회문 검사\n");
		printf("3. 종료\n");
		printf("메뉴 선택: ");
		scanf("%d", &choice);
		printf("\n");
		while (getchar() != '\n');

		switch (choice) {
		case 1:
			printf("회문을 입력하세요: ");
			scanf("%[^\n]s", str);
			printf("\n");
			break;
		case 2:
			break;
		case 3:
			exit(0);
		default:
			printf("잘못된 메뉴 선택입니다.\n");
			printf("\n");
			break;
		}
		if (choice == 1) {
			result = 1;
			top = -1;
			init_queue(&queue);
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i]!='"'&&str[i]!='\''&&str[i]!=','&&str[i]!='.') {
					enqueue(&queue, (int)str[i]);
					push((int)str[i]);
				}				
			}			
		}
		if (choice == 2) {
			for (int i = 0; i < queue.size; i++) {
				a = dequeue(&queue);
				b = pop();
				if (a != b && a + 32 != b && a - 32 != b) result = 0;
				if (result == 0)break;
			}
			if (result == 1)printf("회문입니다.\n\n");
			else  printf("회문이 아닙니다.\n\n");
		}
	}


	return 0;
}

