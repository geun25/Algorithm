#include <stdio.h>
int main()
{
	int n, data[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; i >= 1; j--)
		{
			if (data[j - 1] > data[j])
			{
				int temp;
				temp = data[j-1];
				data[j-1] = data[j];
				data[j] = temp;
			}
			else break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", data[i]);
	}

	return 0;
}