#include <iostream>
using namespace std;
long long int num[91][2];
int main()
{
	int n;
	long long int ans=0;
	cin >> n;
	num[1][1] = 1;
	num[2][0] = 1;
	num[2][1] = 0;
	for (int j = 2; j <= n;j++)
	{
		num[j][0] = num[j - 1][0] + num[j - 1][1];
		num[j][1] = num[j - 1][0];
	}
	for (int i = 0; i < 2; i++)
	{
		ans += num[n][i];
	}
	cout << ans << endl;
}