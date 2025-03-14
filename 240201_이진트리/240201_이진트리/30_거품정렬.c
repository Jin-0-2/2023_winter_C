#include <stdio.h>

void myswap(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void myprint(const int* arr)
{
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				myswap(arr + j, arr + (j + 1));				
			}
			printf(" - "); myprint(arr);
		}
		myprint(arr);
	}
}


int main(void)
{
	int arr[4] = { 3, 2, 4, 1 };

	myprint(arr);
	printf("------------------------------\n");
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	printf("------------------------------\n");
	myprint(arr);

	printf("\n");
	return 0;
}