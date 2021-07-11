// 대표적인 소수 판별 알고리즘 에라토스테네스의 체
#include <stdio.h>
#include <math.h>


/*
bool isPrimeNumber(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
*/

// 시간복잡도 O(N) -> O(N/2)
// 특정 숫자의 제곱근까지만 약수의 여부를 검증

/*
bool isPrimeNumber(int x)
{
    int end = (int)sqrt(x);
    for (int i = 2; i <= end; i++)
    {
        if (x % i == 0)
            return false;
    }
}
*/

int number = 100000;
int a[100001];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= number; i++)
    {
        if (a[i] == 0) // 이미 지워져 있다면 무시
            continue;
        for (int j = i + i; j <= number; j += i) // 자기 자신이 아니라 배수부터 지움
        {
            a[j] = 0;
        }
        for (int i = 2; i <= number; i++)
        {
            if (a[i] != 0)
                printf("%d ", a[i]);
        }
    }
}

int main(void)
{
    //printf("%d", isPrimeNumber(97));
    primeNumberSieve();
    return 0;
}