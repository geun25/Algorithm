#include <stdio.h>

const int MAX = 105;
int n, r;
char result[MAX];
bool check[MAX]; // check[i] == true => ���ĺ� i �� �̹� ������.

void getResult(int x)
// x��° for���� ������ ��.
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
				// x��°�� i�� �ִ� ��� ��츦 �̹� �� �������.
				check[i] = false; // ���ĺ��� i�� �� ������ ���ü� ������ �ʱ�ȭ
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