// 하나의 문제는 단 한 번만 풀도록 하는 알고리즘
// 한 번 푼 것을 여러 번 다시 푸는 비효울적인 알고리즘을 개선시키는 방법
// 피보나치 수열은 분할 정복을 그대로 사용하면 상당히 비효율적
// 1. 큰 문제는 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

// Memoization 사용

#include <stdio.h>

int d[100];

int dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	if (d[x] != 0) // 이미 구한적이 있다면
		return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void)
{
	printf("%d", dp(30));
}