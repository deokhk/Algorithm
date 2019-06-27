#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	for(int qn=0; qn<q; qn++)
	{
		int n;
		cin>>n;
		vector<int> ncandyoftype(n);
		for(int i=0; i<n; i++)
		{
			int t;
			cin>>t;
			ncandyoftype[t-1]++;
		}
		sort(ncandyoftype.begin(),ncandyoftype.end());
		long long int sum=ncandyoftype[n-1];
		int now=ncandyoftype[n-1];
		for(int i=n-2; i>=0; i--)
		{
			if(now==0)
			{
				break;
			}
			if(now==ncandyoftype[i])
			{
				now--;
				sum+=now;
			}
			else if(ncandyoftype[i] < now)
			{
				now=ncandyoftype[i];
				sum+=now;
			}
			else
			{
				now--;
				sum+=now;
			}
		}
		cout<<sum<<'\n';
		
		
	}
}
