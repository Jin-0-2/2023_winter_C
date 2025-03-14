// 15_����_�迭_Ŭ����ȭ.cpp
#include <iostream>
using namespace std;

class MyStack
{
private:
	int* base;
	int max;
	int top; // ������ ���� ������ ��ġ

public:
	MyStack(int _max = 10) : max(_max), top(-1)
	{
		base = new int[max];
	}
	~MyStack()
	{
		delete[] base;
	}

public:
	int get_max() const { return max; }
	int get_top() const { return top; }

public:
	int get_data(int idx) const { return base[idx]; }
	
public:
	void push(int data)
	{
		if (top + 1 >= max)
			throw "Overflow";

		top++;
		base[top] = data;
	}

	int pop()		// ����Լ��� ȣ��Ծ� : �Ͻ������� �ڽ��� �ּҰ� ���޵�.
	{
		if (this->top == -1)
			throw "empty";

		int temp = this->base[this->top];		// ������ ���� ������
		this->top--;
		return  temp;
	}

	int peek()
	{
		if (top == -1)
			throw "empty";

		return base[top];
	}

	void clear()
	{
		top = -1;
	}

	// �����Լ�
	friend void mystack_print(const MyStack &st)
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
	MyStack stack(10);

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