#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct table
{
	int age;
	string name;
	int orsub;
};
table member[100005];
bool cmp(const table &u, const table &v);
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> member[i].age;
		cin >> member[i].name;
		member[i].orsub = i;
	}
	sort(member,member+N,cmp);
	for (int i = 0; i < N; i++)
	{
		cout << member[i].age << " " << member[i].name << '\n';
	}
}
bool cmp(const table &u, const table &v)
{
	if (u.age < v.age)
	{
		return true;
	}
	else if (u.age == v.age)
	{
		return u.orsub < v.orsub;
	}
	else
	{
		return false;
	}
}