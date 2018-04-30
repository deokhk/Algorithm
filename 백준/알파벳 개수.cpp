#include <iostream>
#include <stack>
#include <string>
using namespace std;
int countchar[26];
int main()
{
	stack<char> alphabet;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		alphabet.push(s[i]);
	}
	for (int i = 0; i < s.size(); i++)
	{
		char ch;
		ch = alphabet.top();
		alphabet.pop();
		if (ch == 'a')
		{
			countchar[0]++;
		}
		else if (ch == 'b')
		{
			countchar[1]++;
		}
		else if (ch == 'c')
		{
			countchar[2]++;
		}
		else if (ch == 'd')
		{
			countchar[3]++;
		}
		else if (ch == 'e')
		{
			countchar[4]++;
		}
		else if (ch == 'f')
		{
			countchar[5]++;
		}
		else if (ch == 'g')
		{
			countchar[6]++;
		}
		else if (ch == 'h')
		{
			countchar[7]++;
		}
		else if (ch == 'i')
		{
			countchar[8]++;
		}
		else if (ch == 'j')
		{
			countchar[9]++;
		}
		else if (ch == 'k')
		{
			countchar[10]++;
		}
		else if (ch == 'l')
		{
			countchar[11]++;
		}
		else if (ch == 'm')
		{
			countchar[12]++;
		}
		else if (ch == 'n')
		{
			countchar[13]++;
		}
		else if (ch == 'o')
		{
			countchar[14]++;
		}
		else if (ch == 'p')
		{
			countchar[15]++;
		}
		else if (ch == 'q')
		{
			countchar[16]++;
		}
		else if (ch == 'r')
		{
			countchar[17]++;
		}
		else if (ch == 's')
		{
			countchar[18]++;
		}
		else if (ch == 't')
		{
			countchar[19]++;
		}
		else if (ch == 'u')
		{
			countchar[20]++;
		}
		else if (ch == 'v')
		{
			countchar[21]++;
		}
		else if (ch == 'w')
		{
			countchar[22]++;
		}
		else if (ch == 'x')
		{
			countchar[23]++;
		}
		else if (ch == 'y')
		{
			countchar[24]++;
		}
		else if (ch == 'z')
		{
			countchar[25]++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << countchar[i] << ' ';
	}
}