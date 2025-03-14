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
	int s; //입력받는 출발점입니다
	int e; //입력받는 도착점입니다

	int v[8]; //i번째 정점의 체크상태 (1 : 체크)  //체크시 비교대상 제외
	int distance[8]; //s(출발점)에서 i번째 정점까지의 최단거립니다
	int via[8]; //찾아가는 경로를 저장

	// 그래프는 사전에 주어진 그래프를 사용한다. 지금은 예를들어 표기를 한 것임.
	printf("\n                   <다익스트라(Dijkstra) 알고리즘>                  \n");
	printf("\n 주어진 그래프에서 출발점과 도착점을 입력하면 최단거리를 알려줍니다.");
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


	printf("\n 출발점을 입력하시오. : ");
	scanf_s("%d", &s);
	printf("\n 도착점을 입력하시오. : ");
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
				via[j] = k;/* 추가 part */
			}
		}
	}
	printf("\n %d에서 출발하여, %d로 가는 최단 거리 는 %d입니다.\n\n", s, e, distance[e - 1]);

	int path[8], path_cnt = 0;
	k = e - 1;
	while (1)
	{
		path[path_cnt++] = k;
		if (k == s - 1)break;
		k = via[k];
	}
	printf(" 경로는 : ");
	for (i = path_cnt - 1; i >= 1; i--)
	{
		printf("%d -> ", path[i] + 1);
	}
	printf("%d입니다", path[i] + 1);

	return 0;
}

