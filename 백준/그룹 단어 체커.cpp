#include <iostream>
#include <string>
#include <vector> 
using namespace std;
int main()
{
	int N;
	cin>>N;
	int ans=0;
	for(int tn=0; tn<N; tn++)
	{
		string S;
		cin>>S;
		vector<int> alp(26);
		bool isgroup=true;
		int ssize=S.size();
		for(int i=0; i<ssize; i++)
		{
			if(alp[S[i]-97])
			{
				isgroup=false;
				break;	
			}
			if(S[i]!=S[i+1])
			{
				alp[S[i]-97]=1;
			}
		}
		if(isgroup)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}
