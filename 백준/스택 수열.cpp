#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<char> seq;
	vector<int> isused(n+1);//if already pushed then -> 1
	bool ispossible=true;
	int prevheight=0;
	int height=-1;
	int top=0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		if(height==-1)
		{
			height=arr[i];
			for(int i=1; i<=height ;i++)
			{
				isused[i]=1;
				seq.push_back('+');
			}
			isused[height]=-1;
			seq.push_back('-');
			top=height-1;
		}
		else
		{
			if(height<arr[i])
			{
				prevheight=height;
				height=arr[i];
				for(int i=prevheight+1; i<=height; i++)
				{
					isused[i]=1;
					seq.push_back('+');
				}
				isused[height]=-1;
				seq.push_back('-');
				int tmp=arr[i]-1;
				while(tmp>0 && isused[tmp]==-1)
				{
					tmp--;
				}
				top=tmp;
			}
			else
			{
				if(arr[i]!=top)
				{
					ispossible=false;
					break;
				}
				else
				{
					seq.push_back('-');
					isused[arr[i]]=-1;
					int tmp=arr[i]-1;
					while(tmp>0 && isused[tmp]==-1)
					{
						tmp--;
					}
					top=tmp;
				}
			}
		}
		
	}
	int plussize=0;
	int minussize=0;
	int ssize=seq.size();
	for(int i=0; i<ssize; i++)
	{
		if(seq[i]=='+')
		{
			plussize++;
		}
		else
		{
			minussize++;
		}
	}
	if(!(((ssize/2)==(plussize)) &&((ssize/2)==(minussize))))
	{
		ispossible=false;
	}
	if(ispossible)
	{
		int ssize=seq.size();
		for(int i=0; i<ssize; i++)
		{
			cout<<seq[i]<<'\n';
		}
	}
	else
	{
		cout<<"NO"<<'\n';
	}
	
	
}
