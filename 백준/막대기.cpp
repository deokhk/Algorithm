#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int answer=1;
	vector<int> stick;
	stick.push_back(64);
	int sum=64;
	while(sum>n)
	{
		sort(stick.begin(),stick.end());
		int ssize=stick.size();
		int nsum=stick[0]/2;
		for(int i=1; i<ssize; i++)
		{
			nsum+=stick[i];
		}
		stick[0]=stick[0]/2;
		if(nsum<n)
		{
			stick.push_back(stick[0]);
		}
		sum=0;
		for(int i=0; i<stick.size(); i++)
		{
			sum+=stick[i];
		}
	}
	answer=stick.size();
	cout<<answer<<endl;
}
