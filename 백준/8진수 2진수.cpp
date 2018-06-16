#include <iostream>
#include <string>
using namespace std;
int main()
{
	string number;
	string res;
	cin >> number;
	int orisize = number.size();
	for (int i = 0; i < orisize; i++)
	{
		int orinum = number[i]-'0';
		string mod1, mod2,mod3;
		mod3 = (orinum % 2) + '0';
		orinum = orinum / 2;
		mod2 = (orinum % 2) + '0';
		orinum = orinum / 2;
		mod1 = (orinum % 2) + '0';
		res.append(mod1);
		res.append(mod2);
		res.append(mod3);
	}
	while (number[0] != '0' && res[0] == '0')
	{
		res.erase(0, 1);
	}
	if (number[0] == '0')
	{
		res = "0";
	}
	cout << res << endl;
}