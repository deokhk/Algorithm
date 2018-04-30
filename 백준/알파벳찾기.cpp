#include <iostream>
#include <vector>
#include <string>
using namespace std;
int countchar[26];
int cont[26];
int main()
{
	vector<char> alphabet;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		alphabet.push_back(s[i]);
	}
	for (int j = 0; j < 26; j++)
	{
		countchar[j] = -1;
	}
	for (int i = 0; i < s.size(); i++)
	{
		char ch;
		ch = alphabet.at(i);
		if (ch == 'a')
		{
			if (cont[0] < 1)
			{
				countchar[0] = i;
				cont[0]++;
			}
		}
		else if (ch == 'b')
		{
			if (cont[1] < 1)
			{
				countchar[1] = i;
				cont[1]++;
			}
		}
		else if (ch == 'c')
		{
			if (cont[2] < 1)
			{
				countchar[2] = i;
				cont[2]++;
			}
		}
		else if (ch == 'd')
		{
			if (cont[3] < 1)
			{
				countchar[3] = i;
				cont[3]++;
			}
		}
		else if (ch == 'e')
		{
			if (cont[4] < 1)
			{
				countchar[4] = i;
				cont[4]++;
			}
		}
		else if (ch == 'f')
		{
			if (cont[5] < 1)
			{
				countchar[5] = i;
				cont[5]++;
			}
		}
		else if (ch == 'g')
		{
			
			if (cont[6] < 1)
			{
				countchar[6] = i;
				cont[6]++;
			}
		}
		else if (ch == 'h')
		{
			
			if (cont[7] < 1)
			{
				countchar[7] = i;
				cont[7]++;
			}
		}
		else if (ch == 'i')
		{
			
			if (cont[8] < 1)
			{
				countchar[8] = i;
				cont[8]++;
			}
		}
		else if (ch == 'j')
		{
			if (cont[9] < 1)
			{
				countchar[9] = i;
				cont[9]++;
			}
		}
		else if (ch == 'k')
		{
			if (cont[10] < 1)
			{
				countchar[10] = i;
				cont[10]++;
			}
		}
		else if (ch == 'l')
		{
			if (cont[11] < 1)
			{
				countchar[11] = i;
				cont[11]++;
			}
		}
		else if (ch == 'm')
		{
			
			if (cont[12] < 1)
			{
				countchar[12] = i;
				cont[12]++;
			}
		}
		else if (ch == 'n')
		{
			if (cont[13] < 1)
			{
				countchar[13] = i;
				cont[13]++;
			}
		}
		else if (ch == 'o')
		{
			if (cont[14] < 1)
			{
				countchar[14] = i;
				cont[14]++;
			}
		}
		else if (ch == 'p')
		{
			if (cont[15] < 1)
			{
				countchar[15] = i;
				cont[15]++;
			}
		}
		else if (ch == 'q')
		{
			if (cont[16] < 1)
			{
				countchar[16] = i;
				cont[16]++;
			}
		}
		else if (ch == 'r')
		{
			if (cont[17] < 1)
			{
				countchar[17] = i;
				cont[17]++;
			}
		}
		else if (ch == 's')
		{
			if (cont[18] < 1)
			{
				countchar[18] = i;
				cont[18]++;
			}
		}
		else if (ch == 't')
		{
			if (cont[19] < 1)
			{
				countchar[19] = i;
				cont[19]++;
			}
		}
		else if (ch == 'u')
		{
			if (cont[20] < 1)
			{
				countchar[20] = i;
				cont[20]++;
			}
		}
		else if (ch == 'v')
		{
			if (cont[21] < 1)
			{
				countchar[21] = i;
				cont[21]++;
			}
		}
		else if (ch == 'w')
		{
			if (cont[22] < 1)
			{
				countchar[22] = i;
				cont[22]++;
			}
		}
		else if (ch == 'x')
		{
			if (cont[23] < 1)
			{
				countchar[23] = i;
				cont[23]++;
			}
		}
		else if (ch == 'y')
		{
			if (cont[24] < 1)
			{
				countchar[24] = i;
				cont[24]++;
			}
		}
		else if (ch == 'z')
		{
			if (cont[25] < 1)
			{
				countchar[25] = i;
				cont[25]++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << countchar[i] << ' ';
	}
}