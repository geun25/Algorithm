#include <stdio.h>
// �ð����⵵ O(N*logN)
// Ư���� ���� �������� ū ���ڿ� ���� ���ڸ� ���� ��ȯ�� �ڿ� �迭�� ������ ������.
// �̹� ���ĵǾ��ִ°�� �־��� ���⵵�� ������( O(N^2) )

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6 ,4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) // ���Ұ� 1���� ���
	{
		return;
	}
	int key = start; // Ű�� ù��° ����
	int i = start + 1; // �ε���(���� ��� ����)
	int j = end; // ������ �������
	int temp;

	while (i <= j)
	{
		// �������� ���Ľ� Ű���� ã�� ��ġ�� �ٲ��ָ� �ȴ�(�ε�ȣ)
		while (data[i] <= data[key]) // Ű ������ ū ���� ���� ������
		{
			i++;
		}
		while (data[j] >= data[key] && j > start) // Ű ������ ���� ���� ���� ������
		{
			j--;
		}
		if (i > j) // ���� ������ ���¸� Ű ���� ��ü
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