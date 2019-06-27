#include <iostream>
using namespace std;
bool isendable(long long int k,long long int a,long long int b,long long int n, long long int answer)
{
	if(n<answer || answer<0)
	{
		return false;
	}
	if(k-a*answer-b*(n-answer)>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
long long int bsearch(long long int k, long long int a, long long int b, long long int n, long long int first, long long int last)
{
	long long int target=(first+last)/2;
	if(isendable(k,a,b,n,target) && !isendable(k,a,b,n,target+1))
	{
		return target;
	}
	if(isendable(k,a,b,n,target))
	{
		return bsearch(k,a,b,n,target+1,last);
	}
	else
	{
		return bsearch(k,a,b,n,first,target-1);
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	for(int qn=0; qn<q; qn++)
	{
		long long int k,n,a,b;
		long long int answer=0;
		cin>>k>>n>>a>>b;
		bool iscompletable=true;
		if(k<=n*b)
		{
			iscompletable=false;
		}
		if(iscompletable)
		{
			answer=bsearch(k,a,b,n,0,n);
			cout<<answer<<'\n';
		}
		else
		{
			cout<<"-1"<<'\n';
		}
	}
	
}
