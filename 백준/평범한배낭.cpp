#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int DP[100001][101];
int main()
{
	int N,K;
	cin>>N>>K;
	vector<pair<int ,int> > object;
	for(int i=0; i<N; i++)
	{
		int tw,tv;
		cin>>tw>>tv;
		object.push_back(make_pair(tw,tv));
	}
	for(int j=1; j<=N; j++)
	{
		for(int w=1; w<=K; w++)
		{
			if(object[j-1].first > w)
			{
				DP[w][j]=DP[w][j-1];
			}
			else
			{
				DP[w][j]=max(DP[w][j-1],DP[w-object[j-1].first][j-1]+object[j-1].second);
			}
		}
	}
	cout<<DP[K][N];
	
}
