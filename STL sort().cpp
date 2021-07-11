#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
bool compare(int a, int b)
{
	return a > b;
}
int main(void)
{
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
}
*/



/*
//데이터를 묶어서 정렬하는 방법

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// 정렬 기준은 '점수가 작은 순서'
	bool operator <(Student &student)
	{
		return this->score < student.score;
	}

};

int main(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};

	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << ' ';
	}
}
*/

// pair 라이브러리 사용
// 변수가 2개일 때 1개의 변수 기준으로 정렬
/*
int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "박 한 울"));
	v.push_back(pair<int, string>(85, "이 태 일"));
	v.push_back(pair<int, string>(82, "나 동 빈"));
	v.push_back(pair<int, string>(98, "강 종 구"));
	v.push_back(pair<int, string>(79, "이 상 욱"));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << ' ';
	}
	return 0;
}
*/

// 변수가 3개일 때 2개의 변수 기준으로 정렬

bool compare(pair<string, pair<int, int > > a,
	pair < string, pair<int, int > > b) 
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}
int main(void)
{
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("나 동 빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int> >("이 태 일", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int> >("박 한 울", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int> >("이 상 욱", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int> >("강 종 구", pair<int, int>(88, 19900302)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << ' ';
	}
	return 0;
}


