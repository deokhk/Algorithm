#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct modset
{
	int number;
	int frequent;
};
bool cmp(modset &u,modset &v)
{
	if(u.frequent >v.frequent)
	{
		return true;
	}
	else if(u.frequent==v.frequent)
	{
		return u.number < v.number;
	}
	else
	{
		return false;
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	vector<int> arr(N);
	int sum=0;
	vector<modset> mod(8001);
	for(int i=0; i<8001; i++)
	{
		if(i<=4000)
		{
			mod[i].number=i;
			mod[i].frequent=0;
		}
		else
		{
			mod[i].number=4000-i;
			mod[i].frequent=0;
		}
	}
	for(int i=0; i<N; i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
		if(arr[i]<0)
		{
			mod[4000+abs(arr[i])].frequent++;
		}
		else
		{
			mod[arr[i]].frequent++;
		}
	}
	sort(arr.begin(),arr.end());
	printf("%0.0f\n",round((float)sum/N));
	printf("%d\n",arr[N/2]);
	sort(mod.begin(),mod.end(),cmp);
	if(mod[0].frequent==mod[1].frequent)
	{
		printf("%d\n",mod[1].number);
	}
	else
	{
		printf("%d\n",mod[0].number);
	}
	printf("%d\n",arr[N-1]-arr[0]); 
}
