#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int M,N;
	cin>>M>>N;
	vector<int> primen;
	for(int i=M; i<=N; i++)
	{
		if(i==1)
		{
			continue;
		}
		bool isprime=true;
		for(int j=2; j<i; j++)
		{
			if(i%j==0)
			{
				isprime=false;
				break;
			}
		}
		if(isprime)
		{
			primen.push_back(i);
		}
	}
	sort(primen.begin(),primen.end());
	int sum=0;
	for(int i=0; i<primen.size(); i++)
	{
		sum+=primen[i];
	}
	if(primen.size())
	{
		cout<<sum<<endl;
		cout<<primen[0]<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	
	
}
