#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Knight
{
	int power, coin,pos;
	long long int ans;
};
bool cmp1(const Knight &u, const Knight &v);
bool cmp2(const Knight &u, const Knight &v);
bool cmp3(const Knight &u, const Knight &v);
int main()
{
	int n, k;
	cin >> n >> k;
	vector<Knight> info(n);
	vector<Knight> selected;
	for (int i = 0; i < n; i++)
	{
		cin >> info[i].power;
		info[i].pos = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> info[i].coin;
	}
	sort(info.begin(), info.end(), cmp1);
	for (int i = 0; i < n; i++)
	{
		info[i].ans = info[i].coin;
		int j = 0;
		while (selected.size() > j)
		{
			info[i].ans += selected[j].coin;
			j++;
		}
		if (selected.size() < k)
		{
			selected.push_back(info[i]);
		}
		else
		{
			if (selected.size()>0 && selected[0].coin < info[i].coin)
			{
				selected[0] = info[i];
			}
		}
		if (selected.size() > 0)
		{
			sort(selected.begin(), selected.end(), cmp2);
		}
	}
	sort(info.begin(), info.end(), cmp3);
	int infosize = info.size();
	for (int i = 0; i < infosize; i++)
	{
		cout << info[i].ans << " ";
	}

}
bool cmp1(const Knight &u, const Knight &v)
{
	if (u.power > v.power) {
		return false;
	}
	else if (u.power == v.power)
	{
		return u.coin > v.coin;
	}
	else
	{
		return true;
	}
}
bool cmp2(const Knight &u, const Knight &v)
{
	if (u.coin > v.coin)
	{
		return false;
	}
	else if (u.coin == v.coin)
	{
		return u.power > v.power;
	}
	else
	{
		return true;
	}
}
bool cmp3(const Knight &u, const Knight &v)
{
	if (u.pos > v.pos)
	{
		return false;
	}
	else
	{
		return true;
	}
}

