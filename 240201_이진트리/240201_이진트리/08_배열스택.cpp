//08_�迭����.cpp(Ŭ����)

#include <iostream>
using namespace std;

class MyStack
{
private:
	int *base;  //int �� ������ ���ִ� �迭
	int max;
	int top;	//���� & ���� ��ġ ����

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
	isOverflow();  //���ܸ� ������.

	top++;
	base[top] = value;
	return true;
}

//����
int MyStack::Pop()
{
	isEmpty();

	int temp = base[top];
	top--;
	return temp;
}

//���� ��ܿ� �ִ� ������ ��ȯ
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

	printf("pop 2��\n");
	printf("POP : %d\n", stack.Pop());
	printf("POP : %d\n", stack.Pop());
	stack.Print();

	printf("push : 40, 50\n");
	stack.Push(40);
	stack.Push(50);
	stack.Print();

	printf("pop 1��\n");
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
