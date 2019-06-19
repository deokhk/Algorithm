#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool isexist(vector<int> &a,int start,int end, int numb)
{
	int pivot=(start+end)/2;
	if(start > end)
	{
		return false;
	}
	if(a[pivot]==numb)
	{
		return true;
	}
	else if(a[pivot]<numb)
	{
		return isexist(a,pivot+1,end, numb);
	}
	else
	{
		return isexist(a,0,pivot-1, numb);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int m;
	cin>>m;
	vector<int> target(m);
	for(int i=0; i<m; i++)
	{
		cin>>target[i];
	}
	for(int i=0; i<m; i++)
	{
		if(isexist(a,0,n-1,target[i]))
		{
			cout<<"1"<<'\n';
		}
		else
		{
			cout<<"0"<<'\n';
		}
	}
	
}

