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

void SelSort(int arr[], int n)
{
	int maxIdx;

	for (int i = 0; i < n - 1; i++)
	{
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for (int j = i + 1; j < n; j++)   // �ּҰ� Ž��
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* ��ȯ */
		myswap(&arr[i], &arr[maxIdx]);

		myprint(arr);
	}
}


int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };

	myprint(arr);
	printf("------------------------------\n");

	SelSort(arr, sizeof(arr) / sizeof(int));

	printf("------------------------------\n");
	myprint(arr);

	printf("\n");
	return 0;
}