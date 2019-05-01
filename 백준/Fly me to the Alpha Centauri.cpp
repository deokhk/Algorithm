#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int tn=0; tn<T; tn++)
	{
		int x,y;
		cin>>x>>y;
		long long diff=y-x;
		long long i=0;
		long long answer=0;
		long long dist=0;
		while(diff>dist)
		{
			if(i%2==0)
			{
				dist=((i/2)+1)*((i/2)+1);
			}
			else
			{
				dist=((i+1)/2)*(((i+1)/2)+1);
			}
			i++;
		}
		if(diff==0)
		{
			answer=0;
		}
		else
		{
			answer=i;
		}
		cout<<answer<<endl;
	}
}
