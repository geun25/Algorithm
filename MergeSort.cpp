#include <stdio.h>
// 분할정복방법을 채택, 퀵 정렬과 동일하게 시간복잡도 O(N*logN)
// 피벗 값에 따라서 편향되게 분할할 가능성이 있는 퀵 정렬과 다르게
// 정확히 반절씩 나눈다는 점에서 최악의 경우에도 시간복잡도 O(N*logN) 보장
// 일단 정확히 반으로 나누고 나중에 정렬

// 기존의 데이터를 담을 추가적인 배열 공간이 필요하다는 점에서 메모리 활용 비효율적.

int number = 8;
int sorted[8]; //정렬 배열은 반드시 전역 변수로 선언!!!!!!!!!!!

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	
	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	//남은 데이터도 삽입
	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	
	//정렬된 배열 삽입
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	//크기가 1보다 큰 경우
	if (m < n)
	{
		int middle = (m + n) / 2; // 정확히 반으로 나누고,
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n); // 나중에 합침.
	}
}

int main(void) {
	int array[] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}
}