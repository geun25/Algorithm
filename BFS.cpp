// 너비우선탐색(Breath First Search) : 맹목적인 탐색을 하고자 할 때, 최단경로를 찾아준다는 점에서 최단 길이를 보장해야 할 때 사용
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);


	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[4].push_back(5);
	a[5].push_back(4);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);

	return 0;
}