// 특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 
// 측정하는 최대 유량 문제.

// 가능한 용량의 양을 반복적으로 더함  
// 남아있는 모든 가능한 경로를 더 찾아내기 위해 -> 음의 유량 기록

// 남은 양이 1이 넘으면 계속해서 흘려 보내주면 알아서 최적화가 이루어지기 때문에
// 순서를 고려할 필요 없음.
// BFS 사용하여 모든 가능한 경로를 찾아 남아있는 용량만큼 유량을 흘려보내주는것을 반복
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end)
{
	while (1)
	{
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				// 방문하지 않은 노드 중에서 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) // 흐를수 있는경우 & 노드를 방문하지 않은경우
				{
					q.push(y);
					d[y] = x;     // 경로를 기억
					if (y == end)
						break; // 도착지에 도달을 한 경우
				}
			}    
		}
		//모든 경우를 다 찾은 뒤 탈출
		if (d[end] == -1)
			break;
		int flow = INF;

		// 거꾸로 최소 유량 탐색
		for (int i = end; i != start; i = d[i])
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		//최소 유량만큼 추가
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	printf("%d", result);
}