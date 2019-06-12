#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int n,h,m;
	cin>>n>>h>>m;
	vector<int> rest(n+1);
	for(int i=0; i<n+1; i++)
	{
		rest[i]=-1;
	}
	for(int i=0; i<m; i++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		for(int j=l; j<=r; j++)
		{
			if(rest[j]==-1)
			{
				rest[j]=x;
				continue;
			}
			rest[j]=min(rest[j],x);
		}
	}
	int answer=0;
	for(int i=1; i<=n; i++)
	{
		if(rest[i]!=-1)
		{
			answer+=(rest[i]*rest[i]);
		}
		else
		{
			answer+=(h*h);
		}
	}
	cout<<answer<<endl;
	
}
