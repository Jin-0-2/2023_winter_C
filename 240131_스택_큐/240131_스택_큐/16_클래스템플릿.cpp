// 16_클래스템플릿.cpp
#include <iostream>
using namespace std;

template<typename T>
class MyStack
{
private:
	T* base;
	int max;
	int top; // 마지막 저장 데이터 위치

public:
	MyStack(int _max = 10) : max(_max), top(-1)
	{
		base = new T[max];
	}
	~MyStack()
	{
		delete[] base;
	}

public:
	int get_max() const { return max; }
	int get_top() const { return top; }

public:
	T get_data(int idx) const { return base[idx]; }

public:
	void push(T data)
	{
		if (top + 1 >= max)
			throw "Overflow";

		top++;
		base[top] = data;
	}

	T pop()		// 멤버함수의 호출규약 : 암시적으로 자신의 주소가 전달됨.
	{
		if (this->top == -1)
			throw "empty";

		T temp = this->base[this->top];		// 마지막 저장 데이터
		this->top--;
		return  temp;
	}

	T peek()
	{
		if (top == -1)
			throw "empty";

		return base[top];
	}

	void clear()
	{
		top = -1;
	}

	// 전역함수
	friend void mystack_print(const MyStack& st)
	{
		cout << st.get_top() << " : ";
		for (int i = 0; i <= st.get_top(); i++)
		{
			cout << st.get_data(i) << " ";
		}
		cout << endl;
	}
};

int main()
{
	MyStack<int> stack(10);

	try
	{
		for (int i = 10; i <= 110; i = i + 10)
		{
			stack.push(i);
			mystack_print(stack);
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
			cout << stack.pop() << endl;
			mystack_print(stack);
		}

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	return 0;
}