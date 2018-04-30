#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int i=0;
	while(1)
	{
		int a=0,b=0,c=0,d=0;
		getline(cin,s);
		if(s.size()==0)
		{
			break;
		}
		for(int j=0;j<s.size();j++)
		{
			if(s[j]==32)
			{
				d++;
			}
			else if(65<=s[j] && s[j]<=90)
			{
				b++;
			}
			else if(97<=s[j] && s[j]<=122)
			{
				a++;
			}
			else if(48<=s[j] && s[j]<=57)
			{
				c++;
			}
		}
		cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
		i++;
	}
	
}
