//18_��������(3).cpp
//���� 16���� 17�� ����
//STL���� �����ϴ� stack �����̳ʸ� ���.........................
#include <iostream>
#include <stack>
using namespace std;

//���� ->  ����
void postfix2(char* dst, char* src) 
{
	stack<int> stack;

	while (*src)
	{
		// ')'�� ������ Ǫ�õǾ� �ִ� �����ڸ� ���Ͽ�
		// dst�� �� ��ġ�� ����
		if (*src == ')')
		{
			char oper = stack.top();
			stack.pop();
			*dst = oper;
			dst++;
			//����ó��
			//*dst = ' ';			*dst++;
			src++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')
		{
			stack.push(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{
			//1�� �ڸ� �̻��� ���...			
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			// �̰͵� ���͵� �ƴϸ� �����ϰ� src�� �ϳ� ����
			src++;
	}
	// ���� ǥ����� ���ڿ��� �ڿ� NULL ���� �߰� 
	*dst = 0;
}

int is_legal(char* s) // 1 + 2 (1/2)   1 + 2 + 3 (2/3)
{
	int f = 0;		//
	while (*s)
	{
		while (*s == ' ')   // remove space 
			s++;

		//�����ڸ� ������ --
		if (*s == '+' || *s == '-' || *s =='*' || *s == '/')
			f--;			
		else
		{
			f++;	//�ǿ����ڸ� ������ ++
			while (*s != ' ')
				s++;
		}
		if (f < 1) break;
		s++;
	}
	return (f == 1);   // legal if valuable - operator == 1 
}

int calc1(char* p)
{
	stack<int> stack;

	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			int temp = 0;
			do
			{
				temp = temp * 10 + *p - '0';  //<-----
				p++;
			} while (*p >= '0' && *p <= '9');
			stack.push(temp);
		}
		else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			int num1 = stack.top();	stack.pop();
			int num2 = stack.top();	stack.pop();
			char oper = *p;
			p++;

			int result = 0;
			switch (oper)
			{
			case '+': result = num2 + num1;  break;
			case '-': result = num2 - num1;  break;
			case '*': result = num2 * num1;  break;
			case '/': result = num2 / num1;  break;
			}
			stack.push(result);			//<----------------------- ���� 0
		}
		else
			p++;
	}
	return stack.top();
}

int main()
{	
	char exp[256];
	char inputstr[256];
	cout << "���� �Է�(����ǥ��) : ";   //(1+2)
	gets_s(inputstr, sizeof(inputstr));

	//1. ���� ǥ������� ��ȯ
	postfix2(exp, inputstr);
	printf("\nPostfix : %s", exp);

	//2. ���� �˻�
	if (!is_legal(exp))
	{
		printf("\n Expression is not legal!");
		exit(1);	//���� ����
	}

	//3. ����
	int r = calc1(exp);
	printf("\nAnswer  : %d", r);

	return 0;
}