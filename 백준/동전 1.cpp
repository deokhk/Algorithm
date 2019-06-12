#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int> coin(n);
	for(int i=0; i<n; i++)
	{
		cin>>coin[i];
	}
	for(int j=0; j<n; j++)
	{
		for(int i=1; i<=k; i++)
		{
		if(coin[j]==i)
		{
			dp[i]++;
		}
		else if(coin[j]<i)
		{
			dp[i]+=dp[i-coin[j]];
		}
		}
	}
	cout<<dp[k]<<endl;
}
