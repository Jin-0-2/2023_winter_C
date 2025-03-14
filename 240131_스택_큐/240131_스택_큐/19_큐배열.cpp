// 19_ť�迭.cpp
#include <iostream>
using namespace std;

struct MyQueue
{
	int* base;
	int max;	
	int rear;		// ���� ��ġ	
	int front;		// ���� ��ġ
};

void myqueue_init(MyQueue* q, int _max)
{
	q->max = _max;
	q->rear = 0;		//***
	q->front = 0;
	q->base = new int[_max];
}

void myqueue_exit(MyQueue* q)
{
	delete[] q->base;
}

void myqueue_enqueue(MyQueue* q, int data)
{
	// �����ϳ� ����.
	if ((q->rear + 1) % q->max == q->front)
		throw "Overflow";

	q->base[q->rear] = data;
	q->rear = (q->rear + 1) % q->max; // �����̵�
}

int myqueue_dequeue(MyQueue* q)
{
	if (q->rear == q->front)
		throw "empty";

	int temp = q->base[q->front];		// ������ ���� ������
	q->front = (q->front + 1) % q->max;

	return  temp;
}

int myqueue_peek(MyQueue* q)
{
	if (q->rear == q->front)
		throw "empty";

	return q->base[q->front];
}

void myqueue_clear(MyQueue* q)
{
	q->rear = q->front;
}

void myqueue_print(MyQueue* q)
{
	for (int i = q->front; i != q->rear; i = (i+1)%q->max)
	{
		cout << q->base[i] << " ";
	}
	cout << endl;
}

int main()
{
	MyQueue queue;
	myqueue_init(&queue, 5);

	for (int i = 1; i <= 4; i++)		// 1 2 3 4 [ ]
	{
		myqueue_enqueue(&queue, i);
		myqueue_print(&queue);
	}

	cout << myqueue_dequeue(&queue) << endl;	// [ ] 2 3 4 [ ]
	myqueue_print(&queue);

	myqueue_enqueue(&queue, 5);					// [ ] 2 3 4 5
	myqueue_print(&queue);

	return 0;
}