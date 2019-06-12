#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int flow[503][503];
int capacity[503][503];
int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int> > graph(n);
		for(int i=0; i<m; i++)
		{
			int tu,tv,tc;
			cin>>tu>>tv>>tc;
			graph[tu].push_back(tv);
			graph[tv].push_back(tu);
			capacity[tu][tv]=tc;
		}
		int maxflow=0;
		while(true)
		{
			int prev[n];
			for(int i=0; i<n; i++)
			{
				prev[i]=-1;
			}
			queue<int> q;
			q.push(0);
			prev[0]=0;
			while(!q.empty() && prev[n-1]==-1)
			{
				int now=q.front();
				q.pop();
				int neisize=graph[now].size();
				for(int i=0; i<neisize; i++)
				{
					int next=graph[now][i];
					if(capacity[now][next]>flow[now][next] && prev[next]==-1)
					{
						q.push(next);
						prev[next]=now;
						if(next==n-1)
						{
							break;
						}
					}
				}
			}
				
				if(prev[n-1]==-1)
				{
					break;
				}
				int additional_flow=2100000000;
				
				for(int i=n-1; i!=0; i=prev[i])
				{
					additional_flow=additional_flow > capacity[prev[i]][i]-flow[prev[i]][i] ? capacity[prev[i]][i]-flow[prev[i]][i] : additional_flow;
				}
				for(int i=n-1; i!=0; i=prev[i])
				{
					flow[prev[i]][i]+=additional_flow;
					flow[i][prev[i]]-=additional_flow;
				}
				maxflow+=additional_flow;
	
		}
		cout<<maxflow<<'\n';
		for(int i=0; i<503; i++)
		{
			for(int j=0; j<503; j++)
			{
				flow[i][j]=0;
				capacity[i][j]=0;
			}
		}
		
	}
}
