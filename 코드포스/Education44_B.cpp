#include <iostream>
#include <string>
using namespace std;
int switchlamp[2005][2005];
char lamp[2005][2005];
int checked[2005];
int main()
{
	int n, m;
	cin >> n >> m;
	bool possible = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lamp[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			switchlamp[i][j] = lamp[i][j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < m; j++)
		{
			if (switchlamp[i][j] == 1 && checked[j] == 0)
			{
				checked[j] = 1;
				count++;
			}
		}
		if (count==0)
		{
			possible = false;
			break;
		}
	}
	if (!possible)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
}