#include <iostream>
#include <limits>
#include <algorithm>
int DP[503][503];
int book[503];
int sum[503];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int k;
		cin>>k;
		for(int i=1; i<=k; i++)
		{
			cin>>book[i];
			if(i==1)
			{
				sum[i]=book[i];
			}
			else
			{
				sum[i]=sum[i-1]+book[i];
			}
		}
		for(int i=1; i<=k; i++)
		{
			for(int j=1; i+j<=k; j++)
			{
				if(i==j)
				{
					continue;
				}
				DP[i][i+j]=INT_MAX;
				for(int a=0; a<j; a++)
				{
					int temp=DP[i][i+a]+DP[i+a+1][i+j]+sum[i+j]-sum[i-1];
					DP[i][i+j]=min(DP[i][i+j],temp);
				}
			}
		}
		cout<<DP[1][k]<<endl;
		for(int i=0; i<=k; i++)
		{
			for(int j=0; j<=k; j++)
			{
				DP[i][j]=0;
			}
			book[i]=0;
			sum[i]=0;
		}
		
	}
	
}
