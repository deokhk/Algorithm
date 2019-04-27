#include <iostream>
using namespace std;
int main()
{
	long long int pnum;
	long long city[5];
	scanf("%lld",&pnum);
	scanf("%lld",&city[0]);
	long long mintime=city[0];
	for(int i=1; i<5; i++)
	{
		scanf("%lld",&city[i]);
		mintime=mintime>city[i] ? city[i] : mintime;
	}
	long long answer;
	answer=((pnum-1)/mintime)+5;

	printf("%lld\n",answer);
	
}
