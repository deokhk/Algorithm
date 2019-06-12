#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int l,n;
		cin>>l>>n;
		vector<int> pos(n);
		for(int i=0; i<n; i++)
		{
			cin>>pos[i];
		}
		sort(pos.begin(),pos.end());
		int mivalue=-1;
		for(int i=0; i<n; i++)
		{
			if(mivalue==-1)
			{
				mivalue=abs((l/2)-pos[i]);
				continue;
			}
			mivalue=min(mivalue,abs((l/2)-pos[i]));
		}
		cout<<(l/2)-mivalue<<" ";
		int mavalue=-1;
		for(int i=0; i<n; i++)
		{
			if(mavalue==-1)
			{
				mavalue=l-(abs((l/2)-pos[i]);
				continue;
			}
			mivalue=min(mivalue,abs((l/2)-pos[i]));
		}
	}
}
