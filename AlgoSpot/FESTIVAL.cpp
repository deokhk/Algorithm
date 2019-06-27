#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sum[1001];
int main()
{
	int C;
	cin>>C;
	for(int tn=0; tn<C; tn++)
	{
		int N,L;
		cin>>N>>L;
		vector<int> cost(N);
		for(int i=0; i<N; i++)
		{
			cin>>cost[i];
			sum[i+1]=sum[i]+cost[i];
		}
		double answer=100000;
		for(int length=L; length<=N; length++)
		{
			int day=0;
			while(day+length<=N)
			{
				answer=min(answer,(sum[day+length]-sum[day])/(double)length);
				day++;
			}
		}
		cout<<fixed;
		cout.precision(12);
		cout<<answer<<endl;
		for(int i=0; i<1001; i++)
		{
			sum[i]=0;
		}
	}
}
