#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,a,b;
	string seat;
	cin>>n>>a>>b;
	cin>>seat;
	int inita=a;
	int initb=b;
	for(int i=0; i<n;i++)
	{
		if(i!=0)
		{
			if(seat[i]=='.')
			{
				if(seat[i-1]=='A')
				{
				if(b>0)
				{	seat[i]='B';
					b--;
				}
				else
				{
					seat[i]='.';
				}
				}
				else if(seat[i-1]=='B')
				{
				if(a>0)
				{seat[i]='A';
				a--;
				}
				else
				{
					seat[i]='.';
				}
				}
				else if(seat[i-1]=='*')
				{
				if(a>=b && a>0)
				{
					seat[i]='A';
					a--;
				}
				else if(a<b && b>0)
				{
					seat[i]='B';
					b--;
				}
				}
				else //seat[i-1]�� empty�� ���. �� �ϳ��� �����Ǿ����� �ǹ���. 
				{
				if(a>=b && a>0)
				{
					seat[i]='A';
					a--;
				}
				else if(a<b && b>0)
				{
					seat[i]='B';
					b--;
				}
				}
			}
		}
		else
		{
			if(seat[i]=='.')
			{
				if(a>=b && a>0)
				{
					seat[i]='A';
					a--;
				}
				else if(a<b && b>0)
				{
					seat[i]='B';
					b--;
				}
			}
		}
	}
	int number=inita-a+initb-b;
	cout<<number<<endl;
}
