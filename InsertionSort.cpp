#include <stdio.h>

// 데이터가 거의 정렬된 상태면 가장 효율적.
int main(void) {
	int i, j, temp;
	int array[10] = { 1, 10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++)
	{
		j = i;
		while (array[j] > array[j + 1])
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}