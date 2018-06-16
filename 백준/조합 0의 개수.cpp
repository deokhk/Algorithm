#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	long long int two = 0;
	long long int five = 0;
	for (long long int i = 2; i <= n; i*=2)
	{
		two += n/i;
	}
	for (long long int i = 2; i <= n-m; i *= 2)
	{
		two -= (n-m)/i;
	}
	for (long long int i = 2; i <= m; i *= 2)
	{
		two -= m/i;
	}
	for (long long int i = 5; i <= n; i *= 5)
	{
		five += n/i;
	}
	for (long long int i = 5; i <= n - m; i *= 5)
	{
		five -= (n-m)/i;
	}
	for (long long int i = 5; i <= m; i *= 5)
	{
		five -= m/i;
	}
	long long int res = min(two,five);
	cout << res << endl;
}
