/* 2884 알람시계
#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	b -= 45;
	if (b < 0)
	{
		if (a == 0)
			a = 24;
		a--;
		b += 60;
	}
	cout << a << " " << b;
}
*/

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

/* 1110 더하기 사이클
#include <iostream>

using namespace std;

int main(void)
{
	int n, a, b, c, result, cnt = 0;

	cin >> n;
	result = n;

	while (1)
	{
		a = n % 10;
		b = n / 10;
		c = 10 * a  + (a + b) % 10;
		n = c;
		cnt++;
		if (result == c)
			break;
	}
	cout << cnt;
}
*/

/* 10818 최소,최대
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int max = -1000000;
	int min = 1000000;

	int num, n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		max = num > max ? num : max;
		min = num < min ? num : min;
	}
	cout << min << " " << max;

	return 0;
}
*/

/* 2562 최댓값
#include <iostream>
using namespace std;

int main()
{
	int a[9], index;
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		if(max < a[i])
		{
			max = a[i];
			index = i;
		}
	}
	cout << max << ' ' << index + 1;

	return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int arr[10] = { 0 };

	cin >> a >> b >> c;
	int n = a * b * c;
	
	while (n)
	{
		arr[n % 10] += 1;
		n /= 10; // left shift 
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}