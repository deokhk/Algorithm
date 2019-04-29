#include <iostream>
using namespace std;
int main()
{
	int arr[8];
	for(int i=0; i<8; i++)
	{
		cin>>arr[i];
	}
	int in=0;
	int de=0;
	for(int i=0; i<7; i++)
	{
		if(arr[i]<arr[i+1])
		{
			in++;
		}
		else if(arr[i]>arr[i+1])
		{
			de++;
		}
	}
	
	int state=0;
	 
	if(in==7)
	{
		state=0;
	}
	else if(de==7)
	{
		state=1;
	}
	else
	{
		state=2;
	}
	if(state==0)
	{
		cout<<"ascending"<<endl;
	}
	else if(state==1)
	{
		cout<<"descending"<<endl;
	}
	else
	{
		cout<<"mixed"<<endl;
	}
}
