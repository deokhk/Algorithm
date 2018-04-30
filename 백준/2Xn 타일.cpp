#include <iostream>
#include <deque>
#include <string>
using namespace std;
string way(int n);
string stringadd(string s1, string s2);
string memo[255];
int main()
{
	int z;
	memo[0] = "1";
	memo[1] = "1";
	memo[2] = "3";
	while (cin>>z)
	{
		cout << way(z) << endl;
	}
}
string way(int n)
{
	    if (memo[n] != "")
		{
			return memo[n];
		}
		else
		{
			if (memo[n - 2] != "" && memo[n - 1] != "")
			{
				string temp = stringadd(memo[n - 2], memo[n - 2]);
				memo[n] = stringadd(temp, memo[n - 1]);
				return memo[n];
			}
			else if (memo[n - 2] != "" && memo[n - 1] == "")
			{
				string temp = stringadd(memo[n - 2], memo[n - 2]);
				memo[n] = stringadd(temp, way(n - 1));
				return memo[n];
			}
			else if (memo[n - 1] != "" && memo[n - 2] == "")
			{
				string temp = stringadd(way(n - 2), way(n - 2));
				memo[n] = stringadd(temp, memo[n - 1]);
				return memo[n];
			}
			else
			{
				string temp = stringadd(way(n - 2), way(n - 2));
				memo[n] = stringadd(temp, way(n - 1));
				return memo[n];
			}
		}
}


string stringadd(string s1, string s2)
{
	deque<char> acarry;
	int acarryadd[255];
	for (int i = 0; i < 255; i++)
	{
		acarryadd[i] = 0;
	}
	int size1 = s1.size();
	int size2 = s2.size();
	int size = (size1 > size2) ? size1 : size2;
	int p1 = size + 1 - size1;
	string zero(p1,'0');
	s1 = zero + s1;
	int p2 = size + 1 - size2;
	string azero(p2,'0');
	s2 = azero + s2;
	for (int i = size; i>=0; i--)
	{
		int sum = s1[i] - '0' + s2[i] - '0'+acarryadd[i];
		if (sum < 10)
		{
			char s = sum + '0';
			acarry.push_front(s);
		}
		else
		{
			char s=sum-10+'0';
			acarry.push_front(s);
			if (i != 0)
			{
				acarryadd[i - 1]++;
			}
		}
	}
	string res;
	for (int i = 0; i <=size; i++)
	{
		res.push_back(acarry.at(i));
	}
	if (res[0] == '0')
	{
		res.erase(0, 1);
	}
	return res;
}