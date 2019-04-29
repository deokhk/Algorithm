#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string S;
	cin>>S;
	int ssize=S.size();
	vector<int> alp(26);
	for(int i=0; i<ssize; i++)
	{
		int idx=0;
		if(S[i]>=97)
		{
			idx=S[i]-97;
		}
		else
		{
			idx=S[i]-65;
		}
		alp[idx]++;
	}
	int midx=0;
	int mvalue=-1;
	for(int i=0; i<26; i++)
	{
		if(mvalue<alp[i])
		{
			mvalue=alp[i];
			midx=i;
		}
	}
	bool ismixed=false;
	char ans=midx+65;
	sort(alp.begin(),alp.end());
	if(alp[25]==alp[24])
	{
		ismixed=true;
	}
	if(ismixed)
	{
		cout<<"?"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
}
