#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> Tree[100005];
int check[100005];
long long int dist[100005];
int main()
{
	int v;
	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		int t;
		int temp1 = 0;
		int temp2 = 0;
		cin >> t;
		while (1)
		{
			cin >> temp1;
			if (temp1 != -1)
			{
				cin >> temp2;
				Tree[t].push_back(make_pair(temp1, temp2));
				Tree[temp1].push_back(make_pair(t, temp2));
			}
			else
			{
				break;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	check[1] = 1;
	pair<int,long long int> maxv;
	maxv.first = 1;
	maxv.second = 0;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < Tree[temp.first].size(); i++)
		{
			if (!check[Tree[temp.first][i].first])
			{
				check[Tree[temp.first][i].first] = 1;
				dist[Tree[temp.first][i].first] = dist[temp.first] + Tree[temp.first][i].second;
				q.push(Tree[temp.first][i]);
				if (maxv.second < dist[Tree[temp.first][i].first])
				{
					maxv.first = Tree[temp.first][i].first;
					maxv.second = dist[Tree[temp.first][i].first];
				}
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		check[i] = 0;
		dist[i] = 0;
	}
	int y = maxv.first;
	maxv.second = 0;
	q.push(make_pair(y, 0));
	check[y] = 1;
	maxv.first = y;
	maxv.second = 0;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < Tree[temp.first].size(); i++)
		{
			if (!check[Tree[temp.first][i].first])
			{
				check[Tree[temp.first][i].first] = 1;
				dist[Tree[temp.first][i].first] = dist[temp.first] + Tree[temp.first][i].second;
				q.push(Tree[temp.first][i]);
				if (maxv.second < dist[Tree[temp.first][i].first])
				{
					maxv.first = Tree[temp.first][i].first;
					maxv.second = dist[Tree[temp.first][i].first];
				}
			}
		}
	}
	cout << maxv.second << '\n';
}