#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	int ssize = s.size();
	int tsize = t.size();
	int stemp = ssize;
	int ttemp = tsize;
	int answer = 0;
	while (stemp && ttemp)
	{
		if (s[stemp - 1] == t[ttemp - 1])
		{
			answer++;
			stemp--;
			ttemp--;
		}
		else
		{
			break;
		}
	}
	answer = ssize + tsize - 2 * answer;
	cout << answer << '\n';

}