#include <iostream>
#include <string.h>
using namespace std;
int caldamage(char p[]);
int main()
{
	int t;
	int d;
	int cas=1;
	char p[33];
	cin>>t;
	while(t--)
	{
		bool ispossible=false;
		cin>>d>>p;
		int change=0;
		int size=strlen(p);
		int scount=0;
		for(int i=0; i<size;i++)
		{
			if(p[i]=='S')
			{
				scount++;
			}
		}
		if(scount>d)
		{
			ispossible=false;
		}
		else
		{
			ispossible=true;
		}
		if(ispossible)
		{
		bool youcango=true;
		while(youcango)
		{for(int i=0; i<size;i++)
		{
			int totaldam=caldamage(p);
			if(totaldam<=d)
			{
				ispossible=true;
				youcango=false;
				break;
			}
			else
			{
				if(p[i]=='C' && p[i+1]=='S')
				{
					p[i]='S';
					p[i+1]='C';
					change++;
				}
			}
		}
		}
		if(ispossible)
		{
			cout<<"Case "<<"#"<<cas<<":"<<" "<<change<<endl;
		}
		cas++;
	}
	else
	{
		cout<<"Case "<<"#"<<cas<<":"<<" "<<"IMPOSSIBLE"<<endl;
		cas++;
	}
}
}
int caldamage(char p[])
{
	int dam=1;
	int size;
	size=strlen(p);
	int total=0;
	for(int i=0; i<size; i++)
	{
		if(p[i]=='C')
		{
			dam=dam*2;
		}
		else 
		{
			total=total+dam;
		}
	}
	return total;
}
