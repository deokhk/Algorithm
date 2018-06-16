#include <iostream>
#include <string>
using namespace std;
int main()
{
	int length;
	int count = 0;
	string s;
	cin >> length >> s;
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '1')
		{
			count++;
		}
	}
	string res = "";
	if (count >= 1)
	{
		res = res + "1";
	}
	for (int k = 0; k < length - count; k++)
	{
		res = res + "0";
	}
	cout << res << endl;
}