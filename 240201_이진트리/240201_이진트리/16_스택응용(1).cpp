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

//����ǥ��� -> ���� ǥ���(1�� �ڸ���)
//"(1+(2*3))"
void postfix1(char* dst, char* src)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*src)
	{
		// ')'�� ������ Ǫ�õǾ� �ִ� �����ڸ� ���Ͽ�
		// dst�� �� ��ġ�� ����
		if (*src == ')')
		{
			char oper = mystack_pop(&stack); //������
			*dst = oper;
			*dst++;
			//����ó��
			//*dst = ' ';			*dst++;
			//cout << oper << " ";
			src++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || * src == '*')
		{
			mystack_push(&stack, *src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{			
			// 1�� �ڸ��θ� ������ �ǿ����� ����
			//cout << *src;
			*dst = *src;
			*dst++;
			//����ó��
			//*dst = ' ';			*dst++;
			src++;
			//1�� �ڸ� �̻��� ���...
			/*
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9')
				*dst++ = ' ';
			*/
		}
		else
			// �̰͵� ���͵� �ƴϸ� �����ϰ� src�� �ϳ� ����
			src++;
	}
	// ���� ǥ����� ���ڿ��� �ڿ� NULL ���� �߰� 
	*dst = 0;
}


//����ǥ��� -> ���� ǥ���(1�� �ڸ��̻�)
//"(12+(2*312))"
void postfix2(char* dst, char* src)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*src)
	{
		// ')'�� ������ Ǫ�õǾ� �ִ� �����ڸ� ���Ͽ�
		// dst�� �� ��ġ�� ����
		if (*src == ')')
		{
			char oper = mystack_pop(&stack); //������
			*dst = oper;
			dst++;
			//����ó��
			//*dst = ' ';			*dst++;
			src++;
		}
		else if (*src == '+' || *src == '-' || *src == '/' || *src == '*')
		{
			mystack_push(&stack, *src);
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

int main()
{
	char src[20] = "(1+(2*3))";
	char tar[20] = "";
	postfix1(tar, src);
	
	cout << "����ǥ��� : " << tar << endl; // ABC*+


	char src1[20] = "(12+(2*312))";
	char tar1[20] = "";
	postfix2(tar1, src1);
	cout << "����ǥ��� : " << tar1 << endl; // ABC*+

	return 0;
}