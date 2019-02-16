#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> Tree[100005];
int parent[100005];
int check[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		Tree[u].push_back(v); Tree[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < Tree[temp].size(); i++)
		{
			if (Tree[temp][i] && !check[Tree[temp][i]])
			{
				check[Tree[temp][i]] = 1;
				q.push(Tree[temp][i]);
				parent[Tree[temp][i]] = temp;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}

}