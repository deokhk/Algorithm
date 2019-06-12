#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
long long int manhsum[100003];
long long int xsum[100003];
long long int ysum[100003];
int cityx[100003];
int cityy[100003];
bool xcmp(const tuple<int,int,int> &u, const tuple<int,int,int> &v);
bool ycmp(const tuple<int,int,int> &u, const tuple<int,int,int> &v);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn<t; tn++)
	{
		vector<tuple<int, int, int>> city;
		int n;
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			int tempx, tempy;
			scanf("%d", &tempx);
			scanf("%d", &tempy);
			cityx[i] = tempx;
			cityy[i] = tempy;
			city.push_back(make_tuple(i, tempx, tempy));
		}
		sort(cityx, cityx + n);
		sort(cityy, cityy + n);
		long long int lsum = 0;
		long long int rsum = 0;
		for (int i = 1; i<n; i++)
		{
			rsum += abs(cityx[0] - cityx[i]);
		}
		xsum[0] = rsum + lsum;
		for (int i = 1; i<n; i++)
		{
			int diff = cityx[i] - cityx[i - 1];
			rsum = rsum - diff*(n - i);
			lsum = lsum + diff*i;
			xsum[i] = rsum + lsum;
		}
		lsum = 0;
		rsum = 0;
		for (int i = 1; i<n; i++)
		{
			rsum += abs(cityy[0] - cityy[i]);
		}
		ysum[0] = rsum + lsum;
		for (int i = 1; i<n; i++)
		{
			int diff = cityy[i] - cityy[i - 1];
			rsum = rsum - diff*(n - i);
			lsum = lsum + diff*i;
			ysum[i] = rsum + lsum;
		}
		sort(city.begin(), city.end(), xcmp);
		for (int i = 0; i<n; i++)
		{
			int cx = get<0>(city[i]);
			manhsum[cx] += xsum[i];
		}
		sort(city.begin(), city.end(), ycmp);
		for (int i = 0; i<n; i++)
		{
			int cx = get<0>(city[i]);
			manhsum[cx] += ysum[i];
		}
		sort(manhsum, manhsum + n);
		printf("%lld\n", manhsum[0]);
		for (int i = 0; i < n; i++)
		{
			manhsum[i] = 0;
		}
	}
}
bool xcmp(const tuple<int,int,int> &u, const tuple<int,int,int> &v)
{
	if (get<1>(u)<get<1>(v))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ycmp(const tuple<int,int,int> &u, const tuple<int,int,int> &v)
{
	if (get<2>(u)<get<2>(v))
	{
		return true;
	}
	else
	{
		return false;
	}
}