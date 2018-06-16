#include <iostream>
#include <vector>
using namespace std;
char plate[101][101];
int a[101][101];
int sum[101][101];
int S[101][101];
int main()
{
	int t, r, c, h, v;
	int testcase = 0;
	cin >> t;
	while (t--)
	{
		cin >> r >> c >> h >> v;
		int chocochip = 0;
		int rowcount = 0;
		int colcount = 0;
		int chocorow[150] = { 0 };
		int chococol[150] = { 0 };
		bool possible = true;
		for (int i = 1; i<r + 1; i++)
		{
			for (int j = 1; j<c + 1; j++)
			{
				cin >> plate[i][j];
				if (plate[i][j] == '@')
				{
					a[i][j]++;
					chocochip++;
					chocorow[i]++;
				}
			}
		}
		for (int i = 1; i<c + 1; i++)
		{
			for (int j = 1; j<r + 1; j++)
			{
				if (plate[j][i] == '@')
				{
					chococol[i]++;
				}
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + a[i][j] - sum[i - 1][j - 1];
			}
		}
		if (chocochip % (h + 1) == 0 && chocochip % (v + 1) == 0)
		{
			int rowchoco = chocochip / (h + 1);
			vector<int> possiblerowset;
			for (int i = 1; i<r + 1; i++)
			{
				rowcount = rowcount + chocorow[i];
				if (rowchoco == rowcount)
				{
					possiblerowset.push_back(i);
					rowcount = 0;
				}
			}
			int colchoco = chocochip / (v + 1);
			vector<int> possiblecolset;
			for (int j = 1; j<c + 1; j++)
			{
				colcount = colcount + chococol[j];
				if (colchoco == colcount)
				{
					possiblecolset.push_back(j);
					colcount = 0;
				}
			}
			cout << "row들의 갯수" << possiblerowset.size() << endl;
			for (int i = 0; i < possiblerowset.size(); i++)
			{
				int x = possiblerowset[i];
				cout << i + 1 << "번째 row: " << x << endl;
			}
			cout << "col들의 갯수" << possiblecolset.size() << endl;
			for (int i = 0; i < possiblecolset.size(); i++)
			{
				int x = possiblecolset[i];
				cout << i + 1 << "번째 col: " << x << endl;
			}
			int m = 0;
			int n = 0;
			while (m < possiblerowset.size())
			{
				while (n < possiblecolset.size())
				{
					if (m != 0 && n != 0)
					{
						S[m][n] = sum[possiblerowset[m]][possiblecolset[n]] - sum[possiblerowset[m - 1]][possiblecolset[n]] - sum[possiblerowset[m]][possiblecolset[n - 1]] + sum[possiblerowset[m - 1]][possiblecolset[n - 1]];
					}
					else if (m == 0 && n!=0)
					{
						S[m][n] = sum[possiblerowset[m]][possiblecolset[n]] - sum[0][possiblecolset[n]] - sum[possiblerowset[m]][possiblecolset[n - 1]] + sum[0][possiblecolset[n - 1]];
					}
					else if(n==0 && m!=0)
					{
						S[m][n] = sum[possiblerowset[m]][possiblecolset[n]] - sum[possiblerowset[m - 1]][possiblecolset[n]] - sum[possiblerowset[m]][0] + sum[possiblerowset[m - 1]][0];
					}
					else
					{
						S[m][n] = sum[possiblerowset[m]][possiblecolset[n]] - sum[0][possiblecolset[n]] - sum[possiblerowset[m]][0] + sum[0][0];
					}
					n++;
				}
				m++;
			}
			bool able = false;
			for (int i = 0; !able && i < possiblerowset.size(); i++)
			{
				for (int j = 0; j < possiblecolset.size()-1; j++)
				{
					if (S[i][j] != S[i][j + 1])
					{
						able = true;
						possible = false;
						break;
					}
					cout << "S[" << i << ']' << '[' << j << ']=' << S[i][j] << endl;
				}
			}
		}
		else
		{
			possible = false;
		}
		if (chocochip == 0|| chocochip==r*c)
		{
			possible = true;
		}
		testcase++;
		if (possible)
		{
			cout << "Case #" << testcase << ": POSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << testcase << ": IMPOSSIBLE" << endl;
		}
	}

}