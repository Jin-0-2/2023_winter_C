//중위 표기법 -> 후위 표기법
#include <iostream>
using namespace std;

//---------------------------------------------------- 
typedef struct tagmystack mystack;
struct tagmystack
{
	int* base;  //int 를 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리
};

//초기화
void mystack_init(mystack* pstack, int max)
{
	pstack->max = max;
	pstack->top = -1;
	pstack->base = (int*)malloc(sizeof(int) * max);
}

//종료처리
void mystack_exit(mystack* pstack)
{
	free(pstack->base);
}

//오버플로우 검사
//오버플로우 상태? 오버플로우상태일때 -> true 반환
int isoverflow(const mystack* pstack)
{
	if (pstack->max <= pstack->top + 1)
		return 1;
	else
		return 0;
}

//언더플로우(empty)검사
int isempty(const mystack* pstack)
{
	if (pstack->top == -1)
		return 1;
	else
		return 0;
}

//저장
int mystack_push(mystack* pstack, int value)
{
	if (isoverflow(pstack) == 1)
		return 0;

	pstack->top++;
	pstack->base[pstack->top] = value;
	return 1;
}

//삭제
int mystack_pop(mystack* pstack)
{
	if (isempty(pstack) == 1)
		return 0;

	int temp = pstack->base[pstack->top];
	pstack->top--;
	return temp;
}

//가장 상단에 있는 데이터 반환
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
//1의 자리만
//"123*+";
int calc(char* p)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			mystack_push(&stack, *p - '0');		//<------------------------------- 정수 0
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
			mystack_push(&stack, result);				//<----------------------- 정수 0
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
			mystack_push(&stack, result);				//<----------------------- 정수 0
		}
		else
			p++;
	}
	return mystack_pop(&stack);
}

int main()
{
	char str[20] = "123*+";
	cout << "결과 : " << calc(str) << endl;	//7

	char str1[20] = "123 12 3*+";
	cout << "결과 : " << calc1(str1) << endl;	//159

	return 0;
}