#include <stdio.h>

const int MAX = 105;
int n, r;
char result[MAX];
bool check[MAX]; // check[i] == true => 알파벳 i 가 이미 나왔음.

void getResult(int x)
// x번째 for문을 돌려야 함.
{
	if (x >= r)
		printf("%s\n", result);
	else
	{
		for (int i = 0; i < n; i++)
		{
			char alpha = i + 'a';
			if (!check[i])
			{
				result[x] = alpha;
				check[i] = true;

				getResult(x + 1);
				// x번째에 i를 넣는 모든 경우를 이미 다 고려했음.
				check[i] = false; // 알파벳이 i가 그 다음에 나올수 있음을 초기화
				result[x]   = 0;				  
			}
		}
	}

}
int main() 
{
	scanf_s("%d %d", &n, &r); 

	getResult(0);
	return 0;
}