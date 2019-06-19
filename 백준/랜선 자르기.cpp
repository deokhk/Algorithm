#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int K,N;
bool check(long long int expectation,long long int cut,vector<int> &lan)
{
	int lsize=lan.size();
	long long sum=0;
	for(int i=0; i<lsize; i++)
	{
		sum+=(long long)(lan[i]/cut);
	}
	if(sum>=expectation)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int bsearch(long long int start, long long int end, vector<int> &lan)
{
	long long int pivot=(start+end)/2;
	if(check(N,pivot,lan) && !check(N,pivot+1,lan))
	{
		return pivot;
	}
	else if(check(N,pivot,lan))
	{
		return bsearch(pivot+1,end,lan);
	}
	else
	{
		return bsearch(start,pivot-1,lan);
	}
}
int main()
{
	cin>>K>>N;
	vector<int> lan(K);
	for(int i=0; i<K; i++)
	{
		cin>>lan[i];
	}
	sort(lan.begin(),lan.end());
	long long int fin=lan[lan.size()-1];
	cout<<bsearch(1,fin,lan)<<endl;
}
