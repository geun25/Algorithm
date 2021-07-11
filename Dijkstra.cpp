// 대표적인 최단 경로 탐색 알고리즘. 다익스트라 알고리즘
// 현재까지 알고 있던 최단 경로를 계속해서 갱신 
#include <stdio.h>

int number = 6;
int INF = 1000000000;

//전체 그래프 초기화
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF}, 
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool v[6]; // 방문한 노드
int d[6]; // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환
int getSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++)
	{
		if (d[i] < min && !v[i])
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start)
{
	for (int i = 0; i < number; i++)
	{
		d[i] = a[start][i]; 
	}

	v[start] = true; // 방문처리

	for (int i = 0; i < number - 2; i++)
	{
		int current = getSmallIndex(); // 시간복잡도 O(N^2)
		v[current] = true; // 방문처리
		for (int j = 0; j < number; j++)
		{
			if (!v[j]) // 노드를 방문하지 않았다면
			{
				if (d[current] + a[current][j] < d[j])
				{
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void)
{
	dijkstra(0); 
	for (int i = 0; i < number; i++)
	{
		printf("%d", d[i]); 
	}
}