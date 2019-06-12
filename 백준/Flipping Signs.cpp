#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int DP[100001][2];
int main()
{
	int N;
	cin>>N;
	vector<int> arr(N);
	int mvalue=-1;
	int negativecount=0;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
		if(arr[i]<0)
		{
			negativecount++;
		}
		
		if(mvalue==-1)
		{
			mvalue=abs(arr[i]);
		}
		else
		{
			mvalue=min(mvalue,abs(arr[i]));
		}
		
	}
	long long ans=0;
	for(int i=0; i<N; i++)
	{
		ans+=abs(arr[i]);
	}
	if(negativecount%2!=0)
	{
		ans-=(2*abs(mvalue));
	}
	cout<<ans<<endl;
	
}
