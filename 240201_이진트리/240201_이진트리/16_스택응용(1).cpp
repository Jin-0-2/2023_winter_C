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

//중위표기법 -> 후위 표기법(1의 자리만)
//"(1+(2*3))"
void postfix1(char* dst, char* src)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*src)
	{
		// ')'를 만나면 푸시되어 있던 연산자를 팝하여
		// dst의 현 위치에 저장
		if (*src == ')')
		{
			char oper = mystack_pop(&stack); //연산자
			*dst = oper;
			*dst++;
			//공백처리
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
			// 1의 자리로만 구성된 피연산자 가정
			//cout << *src;
			*dst = *src;
			*dst++;
			//공백처리
			//*dst = ' ';			*dst++;
			src++;
			//1의 자리 이상일 경우...
			/*
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9')
				*dst++ = ' ';
			*/
		}
		else
			// 이것도 저것도 아니면 무시하고 src를 하나 증가
			src++;
	}
	// 후위 표기법의 문자열의 뒤에 NULL 문자 추가 
	*dst = 0;
}


//중위표기법 -> 후위 표기법(1의 자리이상)
//"(12+(2*312))"
void postfix2(char* dst, char* src)
{
	mystack stack;
	mystack_init(&stack, 20);

	while (*src)
	{
		// ')'를 만나면 푸시되어 있던 연산자를 팝하여
		// dst의 현 위치에 저장
		if (*src == ')')
		{
			char oper = mystack_pop(&stack); //연산자
			*dst = oper;
			dst++;
			//공백처리
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
			//1의 자리 이상일 경우...			
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			// 이것도 저것도 아니면 무시하고 src를 하나 증가
			src++;
	}
	// 후위 표기법의 문자열의 뒤에 NULL 문자 추가 
	*dst = 0;
}

int main()
{
	char src[20] = "(1+(2*3))";
	char tar[20] = "";
	postfix1(tar, src);
	
	cout << "후위표기법 : " << tar << endl; // ABC*+


	char src1[20] = "(12+(2*312))";
	char tar1[20] = "";
	postfix2(tar1, src1);
	cout << "후위표기법 : " << tar1 << endl; // ABC*+

	return 0;
}