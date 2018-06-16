#include <iostream>
using namespace std;
int calgcd(int a, int b);
int callcm(int a, int b);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a,b;
		cin >> a >> b;
		int lcm = callcm(a, b);
		cout << lcm << endl;
	}
}
int callcm(int a, int b)
{
	int gcd = calgcd(a, b);
	int mul = a*b;
	int lcm = mul / gcd;
	return lcm;
}
int calgcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	calgcd(b, a%b);
}