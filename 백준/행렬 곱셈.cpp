#include <iostream>
#include <algorithm>
using namespace std;
int fir[101][101];
int sec[101][101];
int ans[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin>>fir[i][j];
		}
	}
	int K;
	cin>>M>>K;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<K; j++)
		{
			cin>>sec[i][j];
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<K; j++)
		{
			for(int k=0; k<M; k++)
			{
				ans[i][j]+=fir[i][k]*sec[k][j];
			}
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<K; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<'\n';
	}
}
