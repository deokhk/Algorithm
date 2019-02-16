#include <iostream>
using namespace std;
int check[100005];
int str[100005];
int A[100005];
int dfs(int x,int count,int start);
int Answer = 0;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				Answer+=dfs(i, 1, i);
			}
		}
		Answer = n - Answer;
		cout << Answer << '\n';
		for (int i = 1; i <= n; i++)
		{
			check[i] = 0;
		}
		Answer = 0;
	}
	
}
int dfs(int x,int count,int start)
{
	if (check[x] == 0)
	{
		str[x] = start;
		check[x] = count;
		dfs(A[x], count + 1, start);
	}
	else if(check[x]!=0 && start==str[x])
	{
		return count - check[x];
	}
	else if (check[x] != 0 && start != str[x])
	{
		return 0;
	}
}