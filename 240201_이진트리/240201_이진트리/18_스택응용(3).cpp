//18_스택응용(3).cpp
//기존 16번과 17번 통합
//STL에서 지원하는 stack 컨테이너를 사용.........................
#include <iostream>
#include <stack>
using namespace std;

//중위 ->  후위
void postfix2(char* dst, char* src) 
{
	stack<int> stack;

	while (*src)
	{
		// ')'를 만나면 푸시되어 있던 연산자를 팝하여
		// dst의 현 위치에 저장
		if (*src == ')')
		{
			char oper = stack.top();
			stack.pop();
			*dst = oper;
			dst++;
			//공백처리
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

int is_legal(char* s) // 1 + 2 (1/2)   1 + 2 + 3 (2/3)
{
	int f = 0;		//
	while (*s)
	{
		while (*s == ' ')   // remove space 
			s++;

		//연산자를 만나면 --
		if (*s == '+' || *s == '-' || *s =='*' || *s == '/')
			f--;			
		else
		{
			f++;	//피연산자를 만나면 ++
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
			stack.push(result);			//<----------------------- 정수 0
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
	cout << "수식 입력(중위표기) : ";   //(1+2)
	gets_s(inputstr, sizeof(inputstr));

	//1. 후위 표기법으로 변환
	postfix2(exp, inputstr);
	printf("\nPostfix : %s", exp);

	//2. 문법 검사
	if (!is_legal(exp))
	{
		printf("\n Expression is not legal!");
		exit(1);	//강제 종료
	}

	//3. 연산
	int r = calc1(exp);
	printf("\nAnswer  : %d", r);

	return 0;
}