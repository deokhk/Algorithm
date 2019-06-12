#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct edge
{
	int start;
	int end;
	int capacity;
};
void dfs(vector<vector<edge > > &Graph, vector<int> &check,int start, long long rainamount);
bool isconnected(vector<vector<edge > > &Graph,int numofnode, long long rainamount);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int V, E;
		scanf("%d %d", &V, &E);
		vector<vector<edge > > Graph(V);
		vector<int> check(V);
		for (int i = 0; i < E; i++)
		{
			int tu, tv, tw;
			scanf("%d %d %d", &tu, &tv, &tw);
			edge tmpu = { tu,tv,tw };
			edge tmpv = { tv,tu,tw };
			Graph[tu].push_back(tmpu);
			Graph[tv].push_back(tmpv);
		}
		long long start=1;
		long long end=pow(2,31);
		long long mid=0;
		int answer=0;
		while(end>=start)
		{
			mid=(start+end)/2;
			bool isc=isconnected(Graph,V,mid);
			if(isc && (isconnected(Graph,V,mid+1)==false))
			{
				answer=mid+1;
				break;
			}
			else if(isc==true)
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		printf("%d\n",answer);
		
	}
}
void dfs(vector<vector<edge > > &Graph, vector<int> &check,int start, long long rainamount)
{
	check[start]=1;
	int neisize=Graph[start].size();
	for(int i=0; i<neisize; i++)
	{
		int next=Graph[start][i].end;
		if(!check[next] && (Graph[start][i].capacity > rainamount))
		{
			dfs(Graph,check,next,rainamount);
		}
	}
}
bool isconnected(vector<vector<edge > > &Graph,int numofnode, long long rainamount)
{
	vector<int> check(numofnode);
	dfs(Graph,check,0,rainamount);
	bool connection=true;
	for(int i=0; i<numofnode; i++)
	{
		if(!check[i])
		{
			connection=false;
			break;
		}
	}
	return connection;
}
