/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calMax(string s);
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		string s;
		cin >> s;
		int Answer = calMax(s);
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
int calMax(string s)
{
	if (s.size() == 1)
	{
		return 0;
	}
	vector<int> partcount;
	stack<pair<char, int>> parencount;
	parencount.push(make_pair('i', -1));
	int len = s.length();
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			parencount.push(make_pair(s[i], i));
		}
		else if (s[i] == '{')
		{
			parencount.push(make_pair(s[i], i));
		}
		else if (s[i] == '[')
		{
			parencount.push(make_pair(s[i], i));
		}
		else if (s[i] == ')')
		{
			if (parencount.top().first == '(')
			{
				parencount.pop();
				count = count + 2;
			}
			else
			{
				partcount.push_back(count);
				count = 0;
			}
		}
		else if (s[i] == '}')
		{
			if (parencount.top().first == '{')
			{
				parencount.pop();
				count = count + 2;
			}
			else
			{
				partcount.push_back(count);
				count = 0;
			}
		}
		else // ] case
		{
			if (parencount.top().first == '[')
			{
				parencount.pop();
				count = count + 2;
			}
			else
			{
				partcount.push_back(count);
				count = 0;
			}
		}
		if (i == len - 1)
		{
			if (parencount.top().first != 'i')
			{
				int stacksize = parencount.size();
				int endindx = s.length() - 1;
				for (int j = 0; j < stacksize; j++)
				{
					if (parencount.size() != 1)
					{
						pair<char, int> temp = parencount.top();
						int tempindx = temp.second;
						string sub = s.substr(tempindx, endindx);
						int aanswer = calMax(sub);
						partcount.push_back(aanswer);
						endindx = tempindx;
						parencount.pop();
					}
				}
			}

		}
	}
	sort(partcount.begin(), partcount.end());
	int vectorlen = partcount.size();
	int Answer = partcount[vectorlen - 1];
	return Answer;
}
