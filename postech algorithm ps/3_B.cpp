#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef struct Edge {
	int endside;
	int length;
	int isevil;
} edge;
int counter = 0;
int n, m;
bool cmp(const edge &u, const edge &v)
{
	if (u.endside < v.endside)
	{
		return true;
	}
	else if (u.endside == v.endside)
	{
		return u.length < v.length;
	}
	else
	{
		return false;
	}
}
int dfs(int start, int parent, vector<int> &check, vector<int> &bridge, vector<vector<edge> > &Graph);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		scanf("%d %d", &n, &m);
		vector<vector<edge> > Graph(n);
		vector<int> bridge;
		vector<int> check(n);
		for (int i = 0; i < n; i++)
		{
			check[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int tu, tv, tl;
			scanf("%d %d %d", &tu, &tv, &tl);
			edge t1 = { tv,tl,0 };
			edge t2 = { tu,tl,0 };
			Graph[tu].push_back(t1);
			Graph[tv].push_back(t2);
		}
		for (int i = 0; i < n; i++)
		{
			int nnsize = Graph[i].size();
			if (nnsize>1)
			{
				sort(Graph[i].begin(), Graph[i].end(), cmp);
				for (int j = 1; j < nnsize; j++)
				{
					if ((Graph[i][j]).endside == (Graph[i][j - 1]).endside)
					{
						//parallel edge
						Graph[i][j].isevil = 1;
						Graph[i][j - 1].isevil = 1;
					}
				}
			}
		}

		dfs(0, -1, bridge, check, Graph);
		int bsize = bridge.size();
		int answer = -1;
		if (bsize)
		{
			sort(bridge.begin(), bridge.end());
			answer = bridge[0];
		}
		printf("%d\n", answer);
		counter = 0;
	}
}
int dfs(int start, int parent, vector<int> &bridge, vector<int> &check, vector<vector<edge> > &Graph)
{
	counter++;
	check[start] = counter;
	int rnodenum = check[start];
	int neisize = Graph[start].size();
	for (int i = 0; i < neisize; i++)
	{
		int nextnode = (Graph[start][i]).endside;
		if (parent != nextnode)
		{
			if (!check[nextnode])//we haven't visited that node!
			{
				int neileast = dfs(nextnode, start, bridge, check, Graph);
				if (neileast> rnodenum)
				{
					if (Graph[start][i].isevil == 0)
					{
						bridge.push_back(Graph[start][i].length);
					}
				}
				rnodenum = rnodenum>neileast ? neileast : rnodenum;

			}
			else
			{
				rnodenum = rnodenum < check[nextnode] ? rnodenum : check[nextnode];
			}
		}
	}
	return rnodenum;

}