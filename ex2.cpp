#include <stdio.h>
#pragma warning(disable: 4996)

int number, data[1000001];

void quickSort(int* data, int start, int end)
{
	if (start >= end) // 원소가 1개인 경우
	{
		return;
	}
	int key = start;
	int i = start + 1, j = end, temp;
	while (i <= j) {
		while (data[i] <= data[key])
		{
			i++;
		}
		while (data[j] >= data[key] && j > start)
		{
			j--;
		}
		if (i > j) // 키 값과 작은값을 교체
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else // 작은값과 큰 값을 교체
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void)
{
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &data[i]);
	}

	quickSort(data, 0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d\n", data[i]);
	}
}