#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int DP[1001][3];
int house[1001][3];
int main()
{
	int N;
	cin>>N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>> house[i][j];
		}
	}
	DP[0][0]=house[0][0];
	DP[0][1]=house[0][1];
	DP[0][2]=house[0][2];
	for(int i=0; i<N; i++)
	{
		DP[i][0]=min(DP[i-1][1],DP[i-1][2])+house[i][0];
		DP[i][1]=min(DP[i-1][0],DP[i-1][2])+house[i][1];
		DP[i][2]=min(DP[i-1][0],DP[i-1][1])+house[i][2];
	}
	vector<int> res;
	res.push_back(DP[N-1][0]);
	res.push_back(DP[N-1][1]);
	res.push_back(DP[N-1][2]);
	sort(res.begin(),res.end());
	cout<<res[0]<<endl;
	
}
