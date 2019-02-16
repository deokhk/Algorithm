#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	long long int ans = 0;
	cin >> n >> m;
	if (n >= 3 && m >= 7)
	{
		ans = 5 + (m - 7);
	}
	else if (n >= 3 && m < 7)
	{
		ans = min(4, (m - 1)+1);
	}
	else
	{
		if (n == 2)
		{
			ans = min(4, ((m - 1) / 2)+1);
		}
		else
		{
			ans = 1;
		}
	}
	cout << ans << '\n';
}