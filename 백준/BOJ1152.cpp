#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S;
	getline(cin, S);
	int Ssize=S.size();
	bool intialphase=true;
	int answer=0;
	for(int i=0; i<Ssize; i++)
	{
		if(intialphase)
		{
			if(S[i]!=' ')
			{
				intialphase=false;
			}
		}
		if(!intialphase)
		{
			if(((i==Ssize-1) && S[i]!=' ') || (S[i]!=' ' && S[i+1]==' '))
			{
				answer++;
			}
		}
	}
	cout<<answer<<endl;
}
