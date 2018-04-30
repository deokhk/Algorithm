#include <iostream>
using namespace std;
int d[1000000];
int div(int x);
int main()
{
	int x;
	int temp = 0;
	cin >> x;
	int count = div(x);
	cout << count << endl;
}
int div(int x)
{
	int temp;
	if (x == 1)
	{
		temp = 0;
		return temp;
	}
	if (d[x - 1] > 0)
	{
		temp = d[x-1] + 1;
	}
	else
	{
		temp = div(x - 1) + 1;
	}
	if (x % 3 == 0)
	{
		if (d[x / 3] > 0)
		{
			if (d[x / 3] + 1 < temp)
			{
				temp = d[x / 3] + 1;
			}
		}
		else
		{
			if (div(x / 3) + 1 < temp)
			{
				temp = div(x / 3) + 1;
			}
		}
	}
	if (x % 2 == 0)
	{
		if (d[x / 2] > 0)
		{
			if (d[x / 2] + 1 < temp)
			{
				temp = d[x / 2] + 1;
			}
		}
		else
		{
			if (div(x / 2) + 1 < temp)
			{
				temp = div(x / 2) + 1;
			}
		}
	}
	d[x] = temp;
	return temp;
}