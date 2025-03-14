// 14_스택_배열.cpp
#include <iostream>
using namespace std;

struct MyStack
{
	int* base;
	int max;
	int top; // 마지막 저장 데이터 위치
	// 저장 및 삭제 위치 관리
};

void mystack_init(MyStack* st, int _max)
{
	st->max = _max;
	st->top = -1;		//***
	st->base = new int[_max];
}

void mystack_exit(MyStack* st)
{
	delete[] st->base;
}

void mystack_push(MyStack* st, int data)
{
	if (st->top + 1 >= st->max)
		throw "Overflow";

	st->top++;
	st->base[st->top] = data;
}

int mystack_pop(MyStack* st)
{
	if (st->top == -1)
		throw "empty";

	int temp = st->base[st->top];		// 마지막 저장 데이터
	st->top--;
	return  temp;
}

int mystack_peek(MyStack* st)
{
	if (st->top == -1)
		throw "empty";

	return st->base[st->top];
}

void mystack_clear(MyStack* st)
{
	st->top = -1;
}

void mystack_print(MyStack* st)
{
	cout << st->top << " : ";
	for (int i = 0; i <= st->top; i++)
	{
		cout << st->base[i] << " ";
	}
	cout << endl;
}

int main()
{
	MyStack stack;
	mystack_init(&stack, 10);

	try
	{
		for (int i = 10; i <= 110; i = i + 10)
		{
			mystack_push(&stack, i);
			mystack_print(&stack);
		}

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	//pop
	try
	{
		for (int i = 0; i < 12; i++)
		{
			cout << mystack_pop(&stack) << endl;
			mystack_print(&stack);
		}

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	return 0;
}