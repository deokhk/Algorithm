#include <iostream>
#include <string>
using namespace std;
int main()
{
	while(true)
	{
	string mystring;
	getline(cin,mystring);
	if(mystring.compare("END"))
	{
		int ssz=mystring.length();
		char rstr[501];
		for(int i=0; i<ssz; i++)
		{
			rstr[i]=mystring.at(ssz-i-1);
			cout<<rstr[i];
		}
	}
	else
	{
		break;
	}
	cout<<'\n';
	}
}
