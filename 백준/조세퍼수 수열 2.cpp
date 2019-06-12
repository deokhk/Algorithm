#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	queue<int> q;
	for(int i=1; i<=N; i++)
	{
		q.push(i);
	}
	cout<<"<";
	while(q.size())
	{
		for(int count=0; count<K; count++)
		{
			if(count==K-1)
			{
				int temp=q.front(); 
				q.pop(); 
				if(q.size())
				{
					cout<<temp<<", ";
				}
				else
				{
					cout<<temp<<">\n";
				}
				continue;
			}
			int temp=q.front();
			q.push(temp);
			q.pop();
		}
	}

}
