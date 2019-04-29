#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int initial=N;
	int clen=0;
	do
	{
		if(N<10)
		{
			N=N*11;
		}
		else
		{
			N=10*(N%10)+((N%10)+(N/10))%10;
		}
		clen++;
	}while(N!=initial);
	cout<<clen<<endl;
}
