#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int N,M;
bool check(int h, vector<int> &tree)
{
	long long int sum=0;
	for(int i=0; i<N; i++)
	{
		sum+=(tree[i]-h>0 ? tree[i]-h : 0);
	}
	if(sum>=M)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int bsearch(long long int start,long long int end,vector<int> &tree)
{
	int pivot=(start+end)/2;
	if(check(pivot,tree) && !check(pivot+1, tree))
	{
		return pivot;
	}
	else if(check(pivot,tree))
	{
		return bsearch(pivot+1,end,tree);
	}
	else
	{
		return bsearch(start,pivot-1,tree);
	}
}
int main()
{
	cin>>N>>M;
	vector<int> tree(N);
	for(int i=0; i<N; i++)
	{
		cin>>tree[i];
	}
	sort(tree.begin(),tree.end());
	int mh=tree[N-1];
	cout<<bsearch(1,mh,tree)<<endl;
	
}
