#include <stdio.h>
// ������������� ä��, �� ���İ� �����ϰ� �ð����⵵ O(N*logN)
// �ǹ� ���� ���� ����ǰ� ������ ���ɼ��� �ִ� �� ���İ� �ٸ���
// ��Ȯ�� ������ �����ٴ� ������ �־��� ��쿡�� �ð����⵵ O(N*logN) ����
// �ϴ� ��Ȯ�� ������ ������ ���߿� ����

// ������ �����͸� ���� �߰����� �迭 ������ �ʿ��ϴٴ� ������ �޸� Ȱ�� ��ȿ����.

int number = 8;
int sorted[8]; //���� �迭�� �ݵ�� ���� ������ ����!!!!!!!!!!!

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	
	//���� ������� �迭�� ����
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

	//���� �����͵� ����
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
	
	//���ĵ� �迭 ����
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	//ũ�Ⱑ 1���� ū ���
	if (m < n)
	{
		int middle = (m + n) / 2; // ��Ȯ�� ������ ������,
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n); // ���߿� ��ħ.
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