 // 위상 정렬은 여러개 의 답이 존재할 수 있음
// 위상 정렬은 Directed Acyclic Graph에만 적용가능, 
// 사이클이 있는 그래프는 시작점이 없기 때문

// 두가지 해결책 제시
// 1. 현재 그래프는 위상 정렬이 가능한지
// 2. 위상 정렬이 가능하다면 그 결과는 무엇인지
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort()
{
	int result[MAX];
	queue<int> q;

	//진입 차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	//위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문
	for (int i = 1; i <= n; i++)
	{
		// n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
		if (q.empty())
		{
			printf("사이클 발생");
			return;
		}

		int x = q.front();
		q.pop ();
		result[i] = x;

		for (int j = 0; j < a[x].size(); j++)
		{
			int y = a[x][j];
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y] == 0)
			{
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << ' ';
	}
}

int main(void)
{
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	topologySort();
}