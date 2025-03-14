#include <stdio.h>

void myprint(const int* arr)
{
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입!

		myprint(arr);
	}
}


int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };

	myprint(arr);
	printf("------------------------------\n");

	InserSort(arr, sizeof(arr) / sizeof(int));

	printf("------------------------------\n");
	myprint(arr);

	printf("\n");
	return 0;
}