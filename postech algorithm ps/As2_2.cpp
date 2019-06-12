#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool cmpx(const pair<long long,long long> &u,const pair<long long,long long> &v)
{
	return u.first<v.first;
}
bool cmpy(const pair<long long,long long> &u,const pair<long long,long long> &v)
{
	return u.second<v.second;
}
long long closestp(int left,int right,vector<pair<long long,long long> > &coors)
{
	int pn=right-left+1;
	int mid=(right+left)/2;
	if(pn<=3)
	{
		if(left<right)
		{
			long long tmin=-1;
			for(int i=left; i<right; i++)
			{
				for(int j=i+1; j<=right; j++)
				{
					long long temp=abs(coors[j].first-coors[i].first)+abs(coors[j].second-coors[i].second);
					if(tmin==-1 | temp<tmin)
					{
						tmin=temp;
					}
				}		
			}
			return tmin;	
		}
		else
		{
			return 0;
		}
	}
	long long cl=closestp(left,mid,coors);
	long long cr=closestp(mid+1,right,coors);
	long long min=cl<cr? cl: cr;
	vector<pair<long long,long long> > vstrip;
	int vsize=0;
	for(int i=left; i<=right; i++)
	{
		if(abs(coors[i].first-coors[mid].first)<min)
		{
			vstrip.push_back(make_pair(coors[i].first,coors[i].second));
			vsize++;
		}
	}
	sort(vstrip.begin(),vstrip.end(),cmpy);
	for(int i=0; i<vsize-1; i++)
	{
		for(int j=i+1; j<vsize && abs(vstrip[j].second-vstrip[i].second)<min; j++)
		{
			if(abs(vstrip[j].first-vstrip[i].first)+abs(vstrip[j].second-vstrip[i].second)<min)
			{
				min=abs(vstrip[j].first-vstrip[i].first)+abs(vstrip[j].second-vstrip[i].second);
			}
		}
	}
	return min;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int tn=0; tn<t; tn++)
	{
		int N;
		scanf("%d",&N);
		vector<pair<long long,long long> > coors;
		long long tx,ty;
		for(int i=0; i<N; i++)
		{
			scanf("%lld",&tx);
			scanf("%lld",&ty);
			coors.push_back(make_pair(tx,ty));
		}
		sort(coors.begin(),coors.end(),cmpx);
		long long dist=closestp(0,N-1,coors);
		printf("%lld \n",dist);
	}
}
