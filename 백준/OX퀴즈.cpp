#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		string s;
		cin>>s;
		int ssize=s.size();
		int mass=0;
		int answer=0;
		for(int i=0; i<ssize; i++)
		{
			if(mass==0  && s[i]=='O')
			{
				mass=1;
				answer+=1;
			}
			else if(mass>0 && s[i]=='O')
			{
				mass++;
				answer+=mass;
			}
			else if(mass>0 && s[i]=='X')
			{
				mass=0;
			}
			
		}
		cout<<answer<<endl;
	}
	
}
