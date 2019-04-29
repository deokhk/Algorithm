#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	vector<pair<long long, long long > > DP;
	DP.push_back(make_pair(1,0));
	DP.push_back(make_pair(0,1));
	for(int i=2; i<=40; i++)
	{
		
		pair<long long, long long> be2=DP[i-2];
		pair<long long ,long long> be1=DP[i-1];
		DP.push_back(make_pair(be2.first+be1.first,be2.second+be1.second));
	}
	for(int tn=0; tn<T; tn++)
	{
		int N;
		cin>>N;
		cout<<DP[N].first<<" "<<DP[N].second<<endl;
	}
}
