#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int q;
	cin>>q;
	for(int qn=0; qn<q; qn++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> pro(n);
		for(int i=0; i<n; i++)
		{
			cin>>pro[i];
		}
		bool ispossible=true;
		int nowmax=0;
		int nowmin=0;
		nowmax=pro[0]+k;
		nowmin=pro[0]-k>1 ? pro[0]-k : 1;
		for(int i=1; i<n; i++)
		{
			int newmax=pro[i]+k;
			int newmin=pro[i]-k>1 ? pro[i]-k : 1;
			if(nowmax < newmin || newmax < nowmin)
			{
				ispossible=false;
				break;
			}
			else
			{
				nowmax=min(nowmax,newmax);
				nowmin=max(nowmin,newmin);
			}
		}
		if(ispossible)
		{
			cout<<nowmax<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
		
	}
}
