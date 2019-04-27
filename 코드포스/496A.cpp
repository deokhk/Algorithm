#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stair[1005];
int stairnum[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stair[i];
	}
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && stair[i] == 1)
		{
			stairnum[total] = stair[i - 1];
			total++;
		}
	}
	cout << total+1 << '\n';
	for (int i = 0; i < total; i++)
	{
		cout << stairnum[i] << " ";
	}
	cout << stair[n-1];
}