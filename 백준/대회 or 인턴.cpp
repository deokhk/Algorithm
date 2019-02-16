#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (n > 2 * m)
	{
		while (n > 2 * m && k)
		{
			n--;
			k--;
		}
		while (k)
		{
			if (n > 2 * (m - 1))
			{
				n--;
				k--;
			}
			else
			{
				m--;
				k--;
			}

		}
	}
	else if (n == 2 * m)
	{
		while (k)
		{
			if (n > 2 * (m - 1))
			{
				n--;
				k--;
			}
			else
			{
				m--;
				k--;
			}

		}
	}
	else
	{
		while (n < 2 * m && k)
		{
			m--;
			k--;
		}
		while (k)
		{
			if (n > 2 * (m - 1))
			{
				n--;
				k--;
			}
			else
			{
				m--;
				k--;
			}

		}
	}
	cout << min(m, n / 2) << '\n';

}