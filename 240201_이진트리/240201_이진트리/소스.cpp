#include <stdio.h>

#define n 8
#define m 5000

int main()
{
	int data[8][8] = {
	{0,2,m,m, m,3,m,m},
	{2,0,4,1, m,m,m,m},
	{m,4,0,m, 3,m,m,m},
	{m,1,m,0, 3,m,2,m},

	{m,m,3,3, 0,m,m,4},
	{3,m,m,m, m,0,6,m},
	{m,m,m,2, m,6,0,4},
	{m,m,m,m, 4,m,4,0} };


	int i = 0, j = 0, k = 0, min = 0;
	int s; //�Է¹޴� ������Դϴ�
	int e; //�Է¹޴� �������Դϴ�

	int v[8]; //i��° ������ üũ���� (1 : üũ)  //üũ�� �񱳴�� ����
	int distance[8]; //s(�����)���� i��° ���������� �ִܰŸ��ϴ�
	int via[8]; //ã�ư��� ��θ� ����

	// �׷����� ������ �־��� �׷����� ����Ѵ�. ������ ������� ǥ�⸦ �� ����.
	printf("\n                   <���ͽ�Ʈ��(Dijkstra) �˰���>                  \n");
	printf("\n �־��� �׷������� ������� �������� �Է��ϸ� �ִܰŸ��� �˷��ݴϴ�.");
	printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n +                                                                 +");
	printf("\n +                         [3]-------3-------[5]                   +");
	printf("\n +                          |                / (                   +");
	printf("\n +                          |               /   (                  +");
	printf("\n +                          4             3      4                 +");
	printf("\n +                          |           /         (                +");
	printf("\n +                          |          /           (               +");
	printf("\n +           [1]-----2-----[2]---1---[4]            [8]            +");
	printf("\n +            (                       (            /               +");
	printf("\n +              (                       (         /                +");
	printf("\n +                3                       2      4                 +");
	printf("\n +                 (                       (    /                  +");
	printf("\n +                  (                       (  /                   +");
	printf("\n +                  [6]----------6-----------[7]                   +");
	printf("\n +                                                                 +");
	printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");


	printf("\n ������� �Է��Ͻÿ�. : ");
	scanf_s("%d", &s);
	printf("\n �������� �Է��Ͻÿ�. : ");
	scanf_s("%d", &e);

	for (j = 0; j < 8; j++)
	{
		v[j] = 0;
		distance[j] = m;
	}// j = 8

	distance[s - 1] = 0;

	for (i = 0; i < 8; i++)
	{

		min = m;
		for (j = 0; j < 8; j++)
		{
			if (v[j] == 0 && distance[j] < min)
			{
				k = j;
				min = distance[j];
			}
		}

		v[k] = 1;

		if (min == m) break;

		for (j = 0; j < 8; j++)
		{
			if (distance[j] > distance[k] + data[k][j]) {
				distance[j] = distance[k] + data[k][j];
				via[j] = k;/* �߰� part */
			}
		}
	}
	printf("\n %d���� ����Ͽ�, %d�� ���� �ִ� �Ÿ� �� %d�Դϴ�.\n\n", s, e, distance[e - 1]);

	int path[8], path_cnt = 0;
	k = e - 1;
	while (1)
	{
		path[path_cnt++] = k;
		if (k == s - 1)break;
		k = via[k];
	}
	printf(" ��δ� : ");
	for (i = path_cnt - 1; i >= 1; i--)
	{
		printf("%d -> ", path[i] + 1);
	}
	printf("%d�Դϴ�", path[i] + 1);

	return 0;
}

