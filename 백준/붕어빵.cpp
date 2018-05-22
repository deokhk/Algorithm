#include <iostream>
using namespace std;
int p[10001];
int tmax[10001];
int calmax(int n);
int temp[10001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		p[i] = x;
	}
	cout << calmax(n) << endl;

}
int calmax(int n)
{
	if (tmax[n] > 0)
	{
		return tmax[n];
	}
	else
	{
		int temmax=p[n];
		for (int i = 1; i < n; i++)
		{
			if (temmax < p[i] + calmax(n - i))
			{
				temmax = p[i] + calmax(n - i);
			}
		}
		tmax[n] = temmax;
		return tmax[n];
	}
}