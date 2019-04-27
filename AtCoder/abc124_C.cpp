#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string S;
	cin>>S;
	int ssize=S.size();
	int zeroone=0;
	for(int i=0; i<ssize; i++)
	{
		if(i%2==0)
		{
			if(S[i]!= '0')
			{
				zeroone++;
			}
		}
		else
		{
			if(S[i]!= '1')
			{
				zeroone++;
			}
		}
	}
	int onezero=0;
	for(int i=0; i<ssize; i++)
	{
		if(i%2==0)
		{
			if(S[i]!='1')
			{
				onezero++;
			}
		}
		else
		{
			if(S[i]!='0')
			{
				onezero++;
			}
		}
	}
	int ans=min(zeroone,onezero);
	cout<<ans<<endl;
}
