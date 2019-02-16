#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	if(N>=100)
	{
		int answer=99;
		for(int i=101; i<=N && i<1000; i++)
		{
			int num=i;
			int x,y,z;
			z=num%10;
			num/=10;
			y=num%10;
			num/=10;
			x=num%10;
			if(y*2==x+z)
			{
				answer++;
			}
		}
		cout<<answer;
	}
	else
	{
		cout<<N;
	}
}
