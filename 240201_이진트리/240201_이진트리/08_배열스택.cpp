//08_배열스택.cpp(클래스)

#include <iostream>
using namespace std;

class MyStack
{
private:
	int *base;  //int 를 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리

public:
	MyStack(int _max = 10);
	~MyStack();

private:
	bool isOverflow() const;
	bool isEmpty() const;

public:
	bool Push(int value);
	int Pop();
	int Peek() const;
	void Print() const;
};

MyStack::MyStack(int _max /* = 10 */)
	:max(_max), top(-1)
{
	base = new int[max];
}

MyStack::~MyStack()
{
	delete[] base;
}

bool MyStack::isOverflow() const
{
	if (max <= top + 1)
		throw "Overflow"; //return true;
	else
		return false;
}

bool MyStack::isEmpty() const
{
	if (top == -1)
		throw "Empty"; // return true;
	else
		return false;
}

bool MyStack::Push(int value)
{
	isOverflow();  //예외를 던진다.

	top++;
	base[top] = value;
	return true;
}

//삭제
int MyStack::Pop()
{
	isEmpty();

	int temp = base[top];
	top--;
	return temp;
}

//가장 상단에 있는 데이터 반환
int MyStack::Peek() const
{
	isEmpty();

	return base[top];
}

void MyStack::Print() const
{
	printf("[%2d] ", top + 1);

	for (int i = 0; i <= top; i++)
	{
		printf("%3d", base[i]);
	}
	printf("\n");
}


int main()
{
	MyStack stack(5);	

	printf("push : 10, 20, 30\n");
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Print();

	printf("pop 2번\n");
	printf("POP : %d\n", stack.Pop());
	printf("POP : %d\n", stack.Pop());
	stack.Print();

	printf("push : 40, 50\n");
	stack.Push(40);
	stack.Push(50);
	stack.Print();

	printf("pop 1번\n");
	printf("POP : %d\n", stack.Pop());
	stack.Print();

	try
	{
		printf("POP : %d\n", stack.Pop());
		printf("POP : %d\n", stack.Pop());
		printf("POP : %d\n", stack.Pop());
		printf("POP : %d\n", stack.Pop());
		printf("POP : %d\n", stack.Pop());
	}
	catch (const char* err)
	{
		printf("POP : %s\n", err);
	}
		
	return 0;
}
