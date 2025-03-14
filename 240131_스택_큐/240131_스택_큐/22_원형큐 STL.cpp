// 22_개선된 원형큐 배열 STL.cpp
#include <iostream>
#include <queue>		// STL queue
using namespace std;
#include <conio.h>

template<typename T>
class MyQueue
{
	T* base;
	int max;
	int rear;		// 저장 위치	
	int front;		// 삭제 위치

public:
	MyQueue(int _max = 10) : max(_max), rear(0), front(0)
	{
		base = new T[_max];
	}
	~MyQueue()
	{
		delete[] base;
	}

public:
	int get_max() const { return max; }
	int get_rear() const { return rear; }
	int get_front() const { return front; }

public:
	T get_data(int idx) const { return base[idx]; }

public:
	void enqueue(int data)
	{
		if ((rear + 1) % max == front)
			throw "Overflow";

		base[rear] = data;
		rear = (rear + 1) % max;
	}

	T dequeue()
	{
		if (rear == front)
			throw "empty";

		T temp = base[front];		// 마지막 저장 데이터
		front = (front + 1) % max;

		return  temp;
	}

	T peak()
	{
		if (rear == front)
			throw "empty";

		return base[front];
	}

	void clear()
	{
		rear = front;
	}

	friend void myqueue_print(const MyQueue& q)
	{
		for (int i = q.get_front(); i != q.get_rear(); i = (i + 1) % q.get_max())
		{
			cout << q.get_data(i) << " ";
		}
		cout << endl;
	}
};



int main()
{
	MyQueue<int> queue(5);

	for (int i = 1; i <= 4; i++)		// 1 2 3 4 [ ]
	{
		queue.enqueue(i);
		myqueue_print(queue);
	}

	cout << queue.dequeue() << endl;	// [ ] 2 3 4 [ ]
	myqueue_print(queue);

	queue.enqueue(5);					// [ ] 2 3 4 5
	myqueue_print(queue);

	return 0;
}