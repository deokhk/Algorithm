#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	/*long long int a = 5;
	long long int b = 2;
	long long int res = a / b;
	cout << res << endl;*/
	long long int n, m;
	int row = 1;
	int col = 1;
	long long int k;
	cin >> n >> m >> k;
	if (k <= n - 1)
	{
		row = row + k;
	}
	else if (k>n-1 && k <= n + m - 2)
	{
		row = n;
		col = col + k - n + 1;
	}
	else if(k>n+m-2 && k<=n*m-1)
	{
		long long int rem = k - (n + m - 2);//남은 이동수
		long long int div = m - 1;
		long long int up = rem / div;
		if (rem%(m - 1) != 0)
		{
			up = up + 1;
		}
		row = n - up;
		if (up % 2 == 0)
		{
			rem = rem - (up - 1)*(m - 1);
			col = 2 + rem-1;
		}
		else
		{
			rem = rem - (up - 1)*(m - 1);
			col = m - rem+1;
		}

	}
	else//전체 이동수보다 더 큰 숫자가 입력된 경우
	{
		row = 1;
		col = 2;
	}
	printf("%d %d", row, col);
}