#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Person
{
	string name;
	int korean, english, math;
};
Person Student[100005];
bool cmp(Person &u, Person &v);
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Student[i].name;
		cin >> Student[i].korean;
		cin >> Student[i].english;
		cin >> Student[i].math;
	}
	sort(Student, Student + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout<<Student[i].name<<'\n';
	}
}
bool cmp(Person &u, Person &v)
{
	if (u.korean > v.korean)
	{
		return true;
	}
	else if (u.korean == v.korean)
	{
		if (u.english < v.english)
		{
			return true;
		}
		else if (u.english == v.english)
		{
			if (u.math > v.math)
			{
				return true;
			}
			else if (u.math == v.math)
			{
				if (u.name.compare(v.name) < 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}