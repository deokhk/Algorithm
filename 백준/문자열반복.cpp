#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int R;
		string S;
		cin>>R>>S;
		string ans="";
		for(int i=0; i<S.size(); i++)
		{
			for(int j=0; j<R; j++)
			{
				ans+=S[i];
			}
		}
		cout<<ans<<endl;
	}
}
