//���� ǥ��� -> ���� ǥ���
#include <iostream>
using namespace std;

//---------------------------------------------------- 
typedef struct tagmystack mystack;
struct tagmystack
{
	int* base;  //int �� ������ ���ִ� �迭
	int max;
	int top;	//���� & ���� ��ġ ����
};

//�ʱ�ȭ
void mystack_init(mystack* pstack, int max)
{
	pstack->max = max;
	pstack->top = -1;
	pstack->base = (int*)malloc(sizeof(int) * max);
}

//����ó��
void mystack_exit(mystack* pstack)
{
	free(pstack->base);
}

//�����÷ο� �˻�
//�����÷ο� ����? �����÷ο�����϶� -> true ��ȯ
int isoverflow(const mystack* pstack)
{
	if (pstack->max <= pstack->top + 1)
		return 1;
	else
		return 0;
}

//����÷ο�(empty)�˻�
int isempty(const mystack* pstack)
{
	if (pstack->top == -1)
		return 1;
	else
		return 0;
}

//����
int mystack_push(mystack* pstack, int value)
{
	if (isoverflow(pstack) == 1)
		return 0;

	pstack->top++;
	pstack->base[pstack->top] = value;
	return 1;
}

//����
int mystack_pop(mystack* pstack)
{
	if (isempty(pstack) == 1)
		return 0;

	int temp = pstack->base[pstack->top];
	pstack->top--;
	return temp;
}

//���� ��ܿ� �ִ� ������ ��ȯ
int mystack_peek(mystack* pstack)
{
	if (isempty(pstack) == 1)
		return 0;

	return pstack->base[pstack->top];
}

void mystack_print(mystack* pstack)
{
	printf("[%2d] ", pstack->top + 1);

	for (int i = 0; i <= pstack->top; i++)
	{
		printf("%3d", pstack->base[i]);
	}
	printf("\n");
}

//-------------------------------------------------------------------------------
//1�� �ڸ���
//"123*+";
int calc(char* p)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			mystack_push(&stack, *p - '0');		//<------------------------------- ���� 0
			p++;
		}
		else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			int num1 = mystack_pop(&stack);
			int num2 = mystack_pop(&stack);
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
			mystack_push(&stack, result);				//<----------------------- ���� 0
		}		
		else
			p++;
	}
	return mystack_pop(&stack);
}

//"123 12 3*+";
int calc1(char* p)
{
	mystack stack;
	mystack_init(&stack, 20);
	
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
			mystack_push(&stack, temp);
		}
		else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			int num1 = mystack_pop(&stack);
			int num2 = mystack_pop(&stack);
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
			mystack_push(&stack, result);				//<----------------------- ���� 0
		}
		else
			p++;
	}
	return mystack_pop(&stack);
}

int main()
{
	char str[20] = "123*+";
	cout << "��� : " << calc(str) << endl;	//7

	char str1[20] = "123 12 3*+";
	cout << "��� : " << calc1(str1) << endl;	//159

	return 0;
}