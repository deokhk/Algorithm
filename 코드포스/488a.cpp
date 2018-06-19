#include <iostream>
#include <vector>
using namespace std;
int seq[11];
int fig[11];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> key;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> fig[i];
	}
	for (int i = 0; i < n; i++)
	{
		int temp = seq[i];
		for (int j = 0; j < m; j++)
		{
			if (temp == fig[j])
			{
				key.push_back(temp);
				break;
			}
		}
	}
	for (int i = 0; i < key.size(); i++)
	{
		cout << key[i] << " ";
	}
}