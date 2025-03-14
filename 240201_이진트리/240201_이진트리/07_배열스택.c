//07_�迭����.c
#include <stdio.h>
#include <malloc.h>

typedef struct tagmystack mystack;
struct tagmystack
{
	int *base;  //int �� ������ ���ִ� �迭
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


int main()
{
	mystack stack;
	mystack_init(&stack, 5);

	printf("push : 10, 20, 30\n");
	mystack_push(&stack, 10);
	mystack_push(&stack, 20);
	mystack_push(&stack, 30);
	mystack_print(&stack);

	printf("pop 2��\n");
	printf("POP : %d\n", mystack_pop(&stack));
	printf("POP : %d\n", mystack_pop(&stack));
	mystack_print(&stack);

	printf("push : 40, 50\n");
	mystack_push(&stack, 40);
	mystack_push(&stack, 50);
	mystack_print(&stack);

	printf("pop 1��\n");
	printf("POP : %d\n", mystack_pop(&stack));
	mystack_print(&stack);

	mystack_exit(&stack);
	return 0;
}
