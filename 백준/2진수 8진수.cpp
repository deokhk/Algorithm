#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
string temp;
int main()
{
	string number;
	cin >> number;
	int ssize = number.size();
	int mod = ssize % 3;
	if (mod == 1)
	{
		temp = "00";
		temp = temp + number;
	}
	else if (mod == 2)
	{
		temp = "0";
		temp = temp + number;
	}
	else
	{
		temp = number;
	}
	int nsize = temp.size() - 1;
	for (int i = 0; i < nsize; i = i + 3)
	{
		char temc = (4 * (temp[i] - '0') + 2 * (temp[i+1] - '0') + 1 * (temp[i+2] - '0')) + '0';
		cout << temc;
	}

}