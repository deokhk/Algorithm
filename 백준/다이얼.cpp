#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string S;
	cin>>S;
	int ssize=S.size();
	vector<int> dial(8);
	for(int i=0; i<ssize; i++)
	{
		int now=S[i]-65;
		if(now<15)
		{
			dial[now/3]++;
		}
		else if(15<=now && now <=18)
		{
			dial[5]++;
		}
		else if(19<=now && now<=21)
		{
			dial[6]++;
		}
		else
		{
			dial[7]++;
		}
	}
	int ans=0;
	for(int i=0; i<8; i++)
	{
		ans+=(dial[i])*(i+3);
	}
	cout<<ans<<endl;
}
