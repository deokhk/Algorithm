#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
int house[30][30];
int check[30][30];
using namespace std;
vector<int> houserate;
queue<pair<int, int>> srch;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d",&house[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (house[i][j] == 1 && check[i][j]==0)
			{
				int count = 0;
				check[i][j] = 1;
				srch.push(make_pair(i, j));
				while (!srch.empty())
				{
					pair<int, int> temp = srch.front();
					srch.pop();
					if (house[temp.first + 1][temp.second] && !check[temp.first + 1][temp.second])
					{
						check[temp.first+1][temp.second] = 1;
						srch.push(make_pair(temp.first + 1, temp.second));
						count++;
					}
					if (house[temp.first][temp.second + 1] && !check[temp.first][temp.second + 1])
					{
						check[temp.first][temp.second + 1] = 1;
						srch.push(make_pair(temp.first, temp.second +1));
						count++;
					}
					if (house[temp.first][temp.second-1] && !check[temp.first][temp.second-1])
					{
						check[temp.first][temp.second-1] = 1;
						srch.push(make_pair(temp.first, temp.second-1));
						count++;
					}
					if (house[temp.first-1][temp.second] && !check[temp.first - 1][temp.second])
					{
						check[temp.first-1][temp.second] = 1;
						srch.push(make_pair(temp.first - 1, temp.second));
						count++;
					}
				}
				houserate.push_back(count+1);
			}	
		}
	}
	sort(houserate.begin(), houserate.end());
	int vectorsize = houserate.size();
	printf("%d\n", vectorsize);
	for (int i = 0; i < vectorsize; i++)
	{
		printf("%d\n",houserate[i]);
	}

}