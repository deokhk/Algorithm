#include <iostream>
#include <algorithm>
using namespace std;
int calgcd(int a, int b);
int main()
{
	int a, b;
	cin >> a >> b;
	int gcd = calgcd(a, b);
	int mul = a*b;
	int lcm = mul / gcd;
	cout << gcd << endl;
	cout << lcm << endl;

}
int calgcd(int a, int b)
{
	if (b == 0)
	{
		cout << "Terminate~!" << endl;
		return a;
	}
	cout << "Hello!" << endl;
	calgcd(b, a%b);
}
