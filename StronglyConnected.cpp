// 같은 SCC에 속하는 두 정점은 서로 도달이 가능
// 기본적으로 사이클이 발생하는 경우 무조건 SCC에 해당하기 때문에 방향그래프일때 의미가 있음
// 부모로 돌아올 수 있어야 SCC성립
#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX]; // 특정 노드에 대해 DFS가 끝났는지 여부 확인
vector<int> a[MAX]; // 인접한 노드
vector<vector<int> > SCC; // 2차원 벡터
stack<int> s;

//DFS는 총 정점의 개수만큼 실행
int dfs(int x)
{
	d[x] = ++id; // 노드마다 고유한 번호 할당
	s.push(x); // 스택에 자기 자신을 삽입

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// 방문하지 않은 이웃  
		if (d[y] == 0)
			parent = min(parent, dfs(y)); // dfs 수행후 더 작은 값으로 값 갱신
		// 처리중인 이웃
		else if (!finished[y]) // 방문은 되었지만, 현재 dfs를 수행하고 있는 노드
			parent = min(parent, d[y]);
	}

	if (parent == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) // 자기 자신값이 나온경우
				break;
		}
		SCC.push_back(scc); // 전체 SCC에 삽입
	}

	//자신의 부모값을 반환합니다.
	return parent;
}

int main(void)
{
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0)
			dfs(i);
	}
	printf("SCC의 개수 : %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++)
	{
		printf("%d번 째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++)
		{
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}

