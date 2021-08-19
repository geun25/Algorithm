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
		int index = i;

		for (int j = i; j < n; j++)
		{
			if (data[index] > data[j])
				index = j; 
		}

		int temp;
		temp = data[i];
		data[i] = data[index];
		data[index] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", data[i]);
	}

	return 0;
}