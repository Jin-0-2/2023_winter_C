//09_배열템플릿.cpp(클래스)

#include <iostream>
using namespace std;

template<typename T>
class MyStack
{
private:
	T *base;  //int 를 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리

public:
	MyStack(int _max = 10);
	~MyStack();

private:
	bool isOverflow() const;
	bool isEmpty() const;

public:
	bool Push(T value);
	T Pop();
	T Peek() const;
	void Print() const;
};

template<typename T>
MyStack<T>::MyStack(int _max /* = 10 */)
	:max(_max), top(-1)
{
	base = new T[max];
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[] base;
}

template<typename T>
bool MyStack<T>::isOverflow() const
{
	if (max <= top + 1)
		throw "Overflow"; //return true;
	else
		return false;
}

template<typename T>
bool MyStack<T>::isEmpty() const
{
	if (top == -1)
		throw "Empty"; // return true;
	else
		return false;
}

template<typename T>
bool MyStack<T>::Push(T value)
{
	isOverflow();  //예외를 던진다.

	top++;
	base[top] = value;
	return true;
}

//삭제
template<typename T>
T MyStack<T>::Pop()
{
	isEmpty();

	T temp = base[top];
	top--;
	return temp;
}

//가장 상단에 있는 데이터 반환
template<typename T>
T MyStack<T>::Peek() const
{
	isEmpty();

	return base[top];
}

template<typename T>
void MyStack<T>::Print() const
{
	printf("[%2d] ", top + 1);

	for (int i = 0; i <= top; i++)
	{
		cout << base[i] << "   ";
	}
	printf("\n");
}


int main()
{
	MyStack<int> stack(5);

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
