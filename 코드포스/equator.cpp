#include <iostream>
using namespace std;
int problem[200001];
int main()
{
	int n;
	int total=0;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>problem[i];
	}
	for(int i=0; i<n; i++)
	{
		total=total+problem[i];
	}
	int day=0;
	int newtotal=0;
	int count;
	if(total%2==0)
	{
		count=total/2;
	}
	else
	{
		count=(total/2)+1;
	}
	for(int i=0; i<n; i++)
	{
		newtotal=newtotal+problem[i];
		day=i;
		if(newtotal>=count)
		{
			break;
		}
	}
	cout<<day+1<<endl;
}
