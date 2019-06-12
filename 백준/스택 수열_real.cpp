#include <iostream>
#include <stack>
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
	vector<char> ans;
	stack<int> s;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int height=-1;
	int topele=0;
	bool ispossible=true;
	for(int ele=0; ele<n; ele++)
	{
		if(height==-1)
		{
			height=arr[ele];
			for(int i=1; i<=height; i++)
			{
				s.push(i);
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
			if(!s.empty())
			{
				topele=s.top();
			}
		}
		else
		{
			if(height<arr[ele])
			{
				for(int i=height+1; i<=arr[ele]; i++)
				{
					s.push(i);
					ans.push_back('+');
				}
				height=arr[ele];
				s.pop();
				ans.push_back('-');
				if(!s.empty())
				{
					topele=s.top();
				}
			}
			else
			{
				if(arr[ele]!=topele)
				{
					ispossible=false;
					break;
				}
				else
				{
					s.pop();
					ans.push_back('-');
					if(!s.empty())
					{
						topele=s.top();
					}
				}
			}
		}
	}
	int plussize=0;
	int minussize=0;
	int ssize=ans.size();
	for(int i=0; i<ssize; i++)
	{
		if(ans[i]=='+')
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
		int ssize=ans.size();
		for(int i=0; i<ssize; i++)
		{
			cout<<ans[i]<<'\n';
		}
	}
	else
	{
		cout<<"NO"<<'\n';
	}
}
