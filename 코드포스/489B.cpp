#include <iostream>
using namespace std;
long long int getgcd(long long int a, long long int b);
int main()
{
	long long int l, r, x, y;
	cin >> l >> r >> x >> y;
	long long int ans = 0;
	long long int mul = x*y;
	if (x != y)
	{
		for (long long int i = 1; i*i <= mul; i++)
		{
			long long int last = mul / i;
			if (mul%i==0 && getgcd(last,i)== x)
			{
				if (l <= i && i <= r && l <= last && last <= r)
				{
					if (last != i)
					{
						ans = ans + 2;
					}
					else
					{
						ans++;
					}
				}
			}
		}
	}
	else
	{
		if (l <= x && x <= r)
		{
			ans++;
		}
	}
	cout << ans << endl;
}
long long int getgcd(long long int a,long long int b)
{
	if (b == 0)
	{
		return a;
	}
	getgcd(b, a%b);
}