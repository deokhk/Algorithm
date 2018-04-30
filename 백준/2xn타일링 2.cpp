#include <iostream>
using namespace std;
int way(int n);
int memo[1002];
int main()
{
	int z;
	memo[1] = 1;
	memo[2] = 2;
	cin >> z;
	cout << way(z) << endl;
	
}
int way(int n)
{
	if (memo[n] != 0)
	{
		return memo[n];
	}
	else
	{
		memo[n] = way(n - 2) + way(n - 1);
		if (memo[n] > 10007)
		{
			memo[n] = memo[n] % 10007;
		}
		return memo[n];
	}
}


