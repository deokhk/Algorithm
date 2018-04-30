#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (97 <= s[i] && s[i] <= 122)
		{
			if (s[i] < 110)
			{
				s[i] = s[i] + 13;
			}
			else
			{
				s[i] = 97 + (12 - (122 - s[i]));
			}
		}
		else if (65 <= s[i] && s[i] <= 90)
		{
			if (s[i] < 78)
			{
				s[i] = s[i] + 13;
			}
			else
			{
				s[i] = 65 + (12 - (90 - s[i]));
			}
		}
	}
	cout << s << endl;
}