#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	string memo;
	cin>>memo;
	int len=memo.length();
	for(int i=0; i<len; i++)
	{
		if(65<=memo[i] && memo[i]<=90)
		{
			cout<<memo[i];
		}
	}
}
