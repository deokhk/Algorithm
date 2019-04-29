#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long contime(vector<long long> &btime,vector<vector<int> > &border,vector<long long> &DP,int number);
int main()
{
	int T;
	cin>>T;
	for(int tn=0; tn<T; tn++)
	{
		int N,K;
		cin>>N>>K;
		vector<long long> btime(N);
		for(int i=0; i<N; i++)
		{
			cin>>btime[i];
		}
		vector<vector<int> > border(N+1);
		vector<long long> DP(N);
		for(int i=0; i<N; i++)
		{
			DP[i]=-1;
		}
		for(int i=0;  i<K; i++)
		{
			int tx,ty;
			cin>>tx>>ty;
			border[ty].push_back(tx);
		}
		int w;
		cin>>w;
		long long timp=contime(btime,border,DP,w);
		cout<<timp<<endl;
	}
}
long long contime(vector<long long> &btime,vector<vector<int> > &border,vector<long long> &DP,int number)
{
	if(border[number].size()==0)
	{
		DP[number-1]=btime[number-1];
		return DP[number-1];
	}
	else
	{
		int bsize=border[number].size();
		long long mint=-1;
		for(int i=0; i<bsize; i++)
		{
			long long tmp=0;
			if(DP[border[number][i]-1]==-1)
			{
				DP[border[number][i]-1]=contime(btime,border,DP,border[number][i]);
				tmp=DP[border[number][i]-1]+btime[number-1];
			}
			else
			{
				tmp=DP[border[number][i]-1]+btime[number-1];
			}
			
			if(mint==-1)
			{
				mint=tmp;
			}
			else
			{
				mint=max(mint,tmp);
			}
		}
		DP[number-1]=mint;
		return DP[number-1];
	}
}
