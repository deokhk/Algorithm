#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<int> rope(N);
	for(int i=0; i<N; i++)
	{
		cin>>rope[i];
	}
	sort(rope.begin(),rope.end());
	int mvalue=-1;
	for(int i=0; i<N; i++)
	{
		if(mvalue==-1)
		{
			mvalue=rope[i]*N;
			continue;
		}
		mvalue=max(mvalue,rope[i]*(N-i));
	}
	cout<<mvalue<<'\n';
}
