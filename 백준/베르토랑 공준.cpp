#include <iostream>
using namespace std;
int main()
{
	int N=0;
	do
	{
		cin>>N;
		if(N==0)
		{
			continue;
		}
		int primecounter=0;
		for(int i=N+1; i<=2*N; i++)
		{
			bool isprime=true;
			for(int j=2; j*j<=i; j++)
			{
				if(i%j==0)
				{
					isprime=false;
					break;
				}
			}
			if(isprime)
			{
				primecounter++;
			}
		}
		cout<<primecounter<<endl;
	}while(N!=0);
}
