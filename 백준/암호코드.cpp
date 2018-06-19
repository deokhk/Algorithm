#include <iostream>
#include <string>
using namespace std;
int DP[5005];
int main()
{
	string number;
	cin >> number;
	int size = number.size();
	DP[0] = 1;
	number = " " + number;
	for (int i = 1; i <= size; i++)
	{
		int units = number[i]-'0';
		if (1 <= units && units <= 9)
		{
			DP[i] = DP[i] + DP[i - 1];
			DP[i] = DP[i] % 1000000;
		}
		if (i == 1)
		{
			continue;
		}
		int tens = number[i - 1] - '0';
		int num = 10 * tens + units;
		if (10 <= num && num <= 26)
		{
			DP[i] = DP[i] + DP[i - 2];
			DP[i] = DP[i] % 1000000;
		}
	}
	cout << DP[size] << endl;
}