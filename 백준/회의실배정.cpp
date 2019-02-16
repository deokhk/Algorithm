#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> &u, pair<int, int> &v);
int main()
{
	int N;
	cin >> N;
	vector<pair<int,int>> conf(N);
	for (int i = 0; i < N; i++)
	{
		cin >> conf[i].first>>conf[i].second;
	}
	int answer = 0;
	sort(conf.begin(), conf.end(),cmp);
	int now = 0;
	for (int i = 0; i < N; i++)
	{
		if (conf[i].first >= now)
		{
			now = conf[i].second;
			answer++;
		}
	}
	cout << answer << '\n';
}
bool cmp(pair<int, int> &u, pair<int, int> &v)
{
	if (u.second > v.second)
	{
		return false;
	}
	else if (u.second == v.second)
	{
		return u.first < v.first;
	}
	else
	{
		return true;
	}
}