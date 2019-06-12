#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfsdp(int start,vector <vector<pair<long long,long long>>> &graph,vector<int> &check,vector<long long> &DP);
int main()
{
	int t;
	scanf("%d", &t);
	for(int tn=0; tn<t; tn++)
	{
		int V, E;
		scanf("%d %d", &V, &E);
		vector <vector<pair<long long, long long>>> graph(V);
		for (int en = 0; en < E; en++)
		{
			int tu, tv, tw;
			scanf("%d %d %d", &tu, &tv, &tw);
			graph[tu].push_back(make_pair(tv, tw));
		}
			vector<int> check(V);
			vector<long long> DP(V);
			for (int i = 0; i < V; i++)
			{
				check[i] = 0;
				DP[i] = 0;
			}
			for (int i = 0; i < V; i++)
			{
				if (!check[i])
				{
					dfsdp(i,graph,check,DP);
				}
			}
			long long ans = DP[0];
			for (int i = 1; i < V; i++)
			{
				ans = DP[i] > ans ? DP[i] : ans;
			}
			printf("%lld\n", ans);
		}
}
void dfsdp(int start,vector <vector<pair<long long, long long>>> &graph,vector<int> &check, vector<long long> &DP)
{
	check[start] = 1;
	int nsize = graph[start].size();
	for (int i = 0; i < nsize; i++)
	{
		int tmp = graph[start][i].first;
		long long dist = graph[start][i].second;
		if (!check[tmp])
		{
			dfsdp(tmp, graph, check, DP);
		}
		DP[start] = DP[start] > (DP[tmp] + dist) ? DP[start] : (DP[tmp]+dist);
	}
}