//11_배열큐.cpp

#include <iostream>
using namespace std;

class MyQueue
{
private:
	int *base;  //int 를 저장할 수있는 배열
	int max;
	int rear;	//저장 위치 관리
	int front;	//삭제 위치 관리

public:
	MyQueue(int _max = 10);
	~MyQueue();

private:
	bool isoverflow() const;
	bool isempty() const;
	int getcount() const;

public:
	bool enqueue(int value);
	int dequeue();
	int peek();
	void print() const;
};

MyQueue::MyQueue(int _max /* = 10*/) : max(_max), rear(0), front(0)
{
	base = new int[max];
}

MyQueue::~MyQueue()
{
	delete[] base;
}

//오버플로우 검사
bool MyQueue::isoverflow() const
{
	if ((rear + 1) % max == front)
		throw "Overflow"; // return true;
	else
		return false;
}

//언더플로우(empty)검사
bool MyQueue::isempty() const
{
	if (rear == front)
		throw "Empty"; // return true;
	else
		return false;
}

//저장
bool MyQueue::enqueue(int value)
{
	isoverflow();

	base[rear] = value;
	rear = (rear + 1) % max;
	return true;
}

//삭제
int MyQueue::dequeue()
{
	isempty();

	int temp = base[front];
	front = (front + 1) % max;
	return temp;
}

//가장 상단에 있는 데이터 반환
int MyQueue::peek()
{
	isempty();

	return base[front];
}

int MyQueue::getcount() const
{
	return (rear - front + max) % max;
}

void MyQueue::print() const
{
	printf("[%2d] ", getcount());

	for (int i = front; i != rear; i = (i + 1) % max)
	{
		printf("%3d", base[i]);
	}
	printf("\n");
}

int main()
{
	MyQueue queue(5);

	printf("put : 10, 20, 30\n");
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.print();

	printf("get 2번\n");
	printf("get : %d\n", queue.dequeue());
	printf("get : %d\n", queue.dequeue());
	queue.print();

	printf("put : 40, 50\n");
	queue.enqueue(40);
	queue.enqueue(50);
	queue.print();

	printf("get 1번\n");
	printf("get : %d\n", queue.dequeue());
	queue.print();

	return 0;
}
