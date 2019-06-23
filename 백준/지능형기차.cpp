#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<pair<int, int> > info;
	for(int i=0; i<4; i++)
	{
		int tout,tin;
		cin>>tout>>tin;
		info.push_back(make_pair(tout,tin));
	}
	int answer=-1;
	int now=0;
	for(int i=0; i<4; i++)
	{
		if(answer==-1)
		{
			answer=info[i].second-info[i].first;
			now=answer;
			continue;
		}
		now=now+info[i].second-info[i].first;
		answer=max(answer,now);
	}
	cout<<answer<<endl;
}
