#include <iostream>
#include <algorithm>
long long int DP[105];
using namespace std;
int main()
{
	int T;
	cin >> T;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		for (int i = 6; i <= N; i++)
		{
			DP[i] = DP[i - 1] + DP[i - 5];
		}
		cout << DP[N] << endl;
		
	}

}