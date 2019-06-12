#include <iostream>
#include <algorithm>
#include <vector>
long long DP[502][502];
int sum[502];
using namespace std;
int mincost(int x, int y)
{
	if(!DP[x][y])
	{
		if(x==y)
		{
			return DP[x][y];
		}
		else
		{
			DP[x][y]=999999999;
			long long temp=0;
			for(int k=0; k<=y-x-1; k++)
			{
				if(!DP[x][x+k])
				{
					temp=DP[x][x+k];
				}
				else
				{
					temp=mincost(x,x+k);
				}
				if(!DP[x+k+1][y])
				{
					temp+=DP[x+k+1][y];
				}
				else
				{
					temp+=mincost(x+k+1,y);
				}
				temp+=(sum[y]-sum[x-1]);
				DP[x][y]=min(DP[x][y],temp);
				
			}
		}
	}
	else
	{
		return DP[x][y];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int K;
		cin>>K;
		vector<int> book(K);
		for(int i=1; i<=K; i++)
		{
			cin>>book[i];
			sum[i]=sum[i-1]+book[i];
		}
		cout<<mincost(1,K)<<'\n';
		for(int i=0; i<=K; i++)
		{
			for(int j=0; j<=K; j++)
			{
				DP[i][j]=0;
			}
			sum[i]=0;
		}
	}
}
