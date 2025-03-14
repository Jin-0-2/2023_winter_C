//10_배열큐.c
#include <stdio.h>
#include <malloc.h>

typedef struct tagmyqueue myqueue;
struct tagmyqueue
{
	int* base;  //int 를 저장할 수있는 배열
	int max;
	int rear;	//저장 위치 관리
	int front;	//삭제 위치 관리
};

//초기화
void myqueue_init(myqueue* pqueue, int max)
{
	pqueue->max		= max;
	pqueue->rear	= 0;
	pqueue->front	= 0;
	pqueue->base	= (int*)malloc(sizeof(int) * max);
}

//종료처리
void myqueue_exit(myqueue* pqueue)
{
	free(pqueue->base);
}

//오버플로우 검사
int isoverflow(const myqueue* pqueue)
{
	if ((pqueue->rear + 1) % pqueue->max == pqueue->front)
		return 1;
	else
		return 0;
}

//언더플로우(empty)검사
int isempty(const myqueue* pqueue)
{
	if (pqueue->rear == pqueue->front)
		return 1;
	else
		return 0;
}

//저장
int myqueue_enqueue(myqueue* pqueue, int value)
{
	if (isoverflow(pqueue) == 1)
		return 0;
		
	pqueue->base[pqueue->rear] = value;
	pqueue->rear = (pqueue->rear + 1) % pqueue->max;
	return 1;
}

//삭제
int myqueue_dequeue(myqueue* pqueue)
{
	if (isempty(pqueue) == 1)
		return 0;

	int temp = pqueue->base[pqueue->front];
	pqueue->front = (pqueue->front + 1) % pqueue->max;
	return temp;
}

//가장 상단에 있는 데이터 반환
int myqueue_peek(myqueue* pqueue)
{
	if (isempty(pqueue) == 1)
		return 0;

	return pqueue->base[pqueue->front];
}

int getcount(myqueue* pqueue)
{
	return (pqueue->rear - pqueue->front + pqueue->max) % pqueue->max;
}

void myqueue_print(myqueue* pqueue)
{
	printf("[%2d] ", getcount(pqueue));

	for (int i = pqueue->front; i != pqueue->rear; i = (i+1)%pqueue->max )
	{
		printf("%3d", pqueue->base[i]);
	}
	printf("\n");
}


int main()
{
	myqueue queue;
	myqueue_init(&queue, 5);

	printf("put : 10, 20, 30\n");
	myqueue_enqueue(&queue, 10);
	myqueue_enqueue(&queue, 20);
	myqueue_enqueue(&queue, 30);
	myqueue_print(&queue);

	printf("get 2번\n");
	printf("get : %d\n", myqueue_dequeue(&queue));
	printf("get : %d\n", myqueue_dequeue(&queue));
	myqueue_print(&queue);

	printf("put : 40, 50\n");
	myqueue_enqueue(&queue, 40);
	myqueue_enqueue(&queue, 50);
	myqueue_print(&queue);

	printf("get 1번\n");
	printf("get : %d\n", myqueue_dequeue(&queue));
	myqueue_print(&queue);

	myqueue_exit(&queue);
	return 0;
}
