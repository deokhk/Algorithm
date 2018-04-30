#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
string s;
int num;
int main()
{
	queue<int> Queue;
	cin >> n;
	while(n--)
	{
		cin >> s;
		if(s=="push")
		{
			cin>>num;
			Queue.push(num);
		}
		else if(s=="pop")
		{
			if(Queue.size())
			{
		    	cout<<Queue.front()<<'\n';
			    Queue.pop();
			}
			else
			{
				cout<<"-1"<<'\n';
			}
			
		}
		else if(s=="size")
		{
			cout<<Queue.size()<<'\n';
		}
		else if(s=="empty")
		{
			cout<<Queue.empty()<<'\n';
		}
		else if(s=="front")
		{
			if(Queue.empty())
			{
				cout<<"-1"<<'\n';
			}
			else
			{
				cout<<Queue.front()<<'\n';
			}
		}
		else 
		{
			if(Queue.empty())
			{
				cout<<"-1"<<'\n';
			}
			else
			{
				cout<<Queue.back()<<'\n';
			}
		}
	}
}
