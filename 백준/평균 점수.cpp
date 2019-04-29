#include <iostream>
using namespace std;
int main()
{
	int arr[5];
	int av=0;
	for(int i=0; i<5; i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<40)
		{
			av+=40;
		}
		else
		{
			av+=arr[i];
		}
	}
	printf("%d\n",av/5);
}
