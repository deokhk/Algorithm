#include <iostream>
int testcase[101];
using namespace std;
int calgcd(int a, int b);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> testcase[i];
		}
		long long int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += calgcd(testcase[i], testcase[j]);
			}
		}
		//intialize the test array
		for (int i = 0; i < n; i++)
		{
			testcase[i] = 0;
		}
		cout << sum << endl;
	}
}
int calgcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	calgcd(b, a%b);
}