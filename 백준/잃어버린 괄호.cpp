#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> numbers;
	vector<char> signs;
	string seq;
	cin >> seq;
	string num = "";
    for (int i = 0; i < seq.size(); i++)
	{
		while (i < seq.size() && seq[i] != '+' && seq[i] != '-')
		{
			num += seq[i];
			i++;
		}
		numbers.push_back(atoi(num.c_str()));
		num = "";
		signs.push_back(seq[i]);
	}
	int answer = numbers[0];
	if (signs.size() > 0)
	{
		int i = 0;
		while (signs[i] == '+')
		{
			answer += numbers[i + 1];
			i++;
		}
		for (int j = i+1; j < numbers.size(); j++)
		{
			answer -= numbers[j];
		}
	}
	cout << answer << '\n';
}