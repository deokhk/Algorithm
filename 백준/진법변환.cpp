#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int B;
	string number;
	int conv = 0;
	cin >> number >> B;
	int j = 0;
	for (int i = number.size()-1; i >= 0; i--)
	{
		int num;
		if (number[i] <= '9')
		{
			num = number[i] - '0';
		}
		else
		{
			num = number[i] - 'A' + 10;
		}
		conv += num*pow(B, j);
		j++;
	}
	cout << conv << endl;

}