#include <iostream>
#include <algorithm>
using namespace std;
int f[501];
int sum[501];
int dp[501][501];
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
		for(int i=1; i<=K; i++)
		{
			cin>>f[i];
			sum[i]=sum[i-1]+f[i];
		}
		for(int i=1; i<=K; i++)
		{
			for(int j=i-1; j>=1; j--)
			{
				dp[j][i]=99999999;
				if(j==i-1)
				{
					dp[j][i]=f[i]+f[j];
				}
				else
				{
					for(int k=j; k<i; k++)
					{
						int sos=dp[j][k]+dp[k+1][i]+sum[i]-sum[j-1];
						dp[j][i]=sos<dp[j][i] ? sos : dp[j][i];
					}
				}
			}
		}
		cout<<dp[1][K]<<endl;
		for(int i=1; i<=501; i++)
		{
			f[i]=0;
			sum[i]=0;
			for(int j=1; j<=501; j++)
			{
				dp[i][j]=0;
			}
		}
	}
	
}
