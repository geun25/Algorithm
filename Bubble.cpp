#include <stdio.h>
int main()
{
	int n;
	int data[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; i < n-i-1; i++)
		{
			if (data[j] > data[j + 1])
			{
				int temp;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}				
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", data[i]);
	}

	return 0;  
}
