#include <stdio.h>
// 시간복잡도 O(N*logN)
// 특정한 값을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눈다.
// 이미 정렬되어있는경우 최악의 복잡도를 가진다( O(N^2) )

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6 ,4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) // 원소가 1개인 경우
	{
		return;
	}
	int key = start; // 키는 첫번째 원소
	int i = start + 1; // 인덱스(왼쪽 출발 지점)
	int j = end; // 오른쪽 출발지점
	int temp;

	while (i <= j)
	{
		// 내림차순 정렬시 키값을 찾는 위치만 바꿔주면 된다(부등호)
		while (data[i] <= data[key]) // 키 값보다 큰 값을 만날 때까지
		{
			i++;
		}
		while (data[j] >= data[key] && j > start) // 키 값보다 작은 값을 만날 때까지
		{
			j--;
		}
		if (i > j) // 현재 엇갈린 상태면 키 값과 교체
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j+1, end);
}
int main(void) {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", data[i]);
	}
	return 0;
}