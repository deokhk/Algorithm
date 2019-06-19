#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,M;
	cin>>n>>M;
	vector<int> tcost(n);
	for(int i=0; i<n; i++)
	{
		cin>>tcost[i];
	}
	cout<<"0 ";
	for(int i=1; i<n; i++)
	{
		vector<int> tmp;
		for(int j=0; j<i; j++)
		{
			tmp.push_back(tcost[j]);
		}
		sort(tmp.begin(),tmp.end());
		int sum=tcost[i];
		for(int j=0; j<i; j++)
		{
			sum+=tmp[j];
		}
		if(sum<=M)
		{
			cout<<"0 ";
		}
		else
		{
			int ans=0;
			int start=i-1;
			while(sum>M)
			{
				sum-=tmp[start];
				start--;
				ans++;
			}
			cout<<ans<<" ";
		}
		
	}
}
