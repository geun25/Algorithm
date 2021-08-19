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

/* 2577 숫자의 개수
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
*/

/* 4344 평균은 넘겠지
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int C, N, cnt;
	double avg;
	int a[1000] = { 0 };
	double result;

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		avg = 0;
		cnt = 0;

		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> a[j];
			avg += a[j];
		}

		avg = avg / N;

		for (int j = 0; j < N; j++)
		{
			if (a[j] > avg)
				cnt++;
		}
		result = (double)cnt / N * 100;

		cout << fixed;
		cout.precision(3);
		cout << result << "%" << endl;
	}
}
*/

/* 1157 단어공부
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string c;
	cin >> c;
	int max = 0;
	int cnt = 0;
	int target;
	int a[26] = { 0, };

	transform(c.begin(), c.end(), c.begin(), (int(*)(int))toupper);
	for (int i = 0; i < c.length(); i++)
	{
		a[c[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			cnt = 0;
			target = i;
		}
		if (max == a[i])
			cnt++;
	}

	if (cnt > 1)
		cout << "?";
	else
		cout << (char)(target + 'A');
}
*/

/* 1152 단어의 개수
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a;
	int cnt = 0;
	bool space = false;
	getline(cin, a);
	if (a.empty())
	{
		cout << "0";
		return 0;
	}

	cnt = 1;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
			cnt++;
	}
	if (a[0] == ' ')
		cnt--;
	if (a[a.length() - 1] == ' ')
		cnt--;
	cout << cnt;
	return 0;
}
*/

/* 2941 크로아티아 알파벳
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int idx;
	string str;
	cin >> str;
	for (int i = 0; i < croatian.size(); i++)
	{
		while (1)
		{
			idx = str.find(croatian[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, croatian[i].length(), "#");
		}
	}
	cout << str.length();
}
*/

/* 1316 그룹 단어 체커
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
	int num;
	cin >> num;
	string *str;
	str = new string[num];
	int idx[26] = {0,};
	bool status = true;
	int count = 0;
	for(int i = 0; i < num; i++)
	{
		cin >> str[i];
	}
	for(int i = 0; i < num; i++)
	{
		status = true;
		memset(idx,0,sizeof(idx));
		for(int j = 0; j < str[i].length(); j++)
		{
			if(idx[str[i][j]-'a'] != 0)
				if(str[i][j-1] != str[i][j])
				{
					status = false;
					break;
				}
			idx[str[i][j]-'a']++;
		}
		if(status)
			count++;
	}
	cout <<count;
}
*/