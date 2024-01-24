// 04_함수인자전달.c

#include <stdio.h>

void print_star10();
void print_star20();
void print_star(int count);
void printf_shape(char c, int count);

void main()
{
	print_star10();
	print_star20();
	print_star(10);
	print_star(20);
	print_star(30);
	printf_shape('#', 40);
}

void print_star10()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%c", '*');
	}
	printf("\n");
}

void print_star20()
{
	for (int i = 0; i < 20; i++)
	{
		printf("%c", '*');
	}
	printf("\n");
}
void print_star(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c", '*');
	}
	printf("\n");
}

void printf_shape(char c, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}