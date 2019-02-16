#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int zero = 0;
	vector<int> plus;
	vector<int> minus;
	int one = 0;
	int answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
		{
			if (temp == 1)
			{
				one++;
			}
			else
			{
				plus.push_back(temp);
			}
		}
		else if (temp == 0)
		{
			zero++;
		}
		else
		{
			minus.push_back(-temp);
		}
	}
	sort(plus.begin(),plus.end());
	sort(minus.begin(), minus.end());
	if (plus.size() % 2 == 0)
	{
		for (int i = plus.size()-1; i >0; i = i - 2)
		{
			answer+=plus[i] * plus[i - 1];
		}
	}
	else
	{
		for (int i = plus.size()-1; i >0; i = i - 2)
		{
			answer += plus[i] * plus[i - 1];
		}
		answer += plus[0];
	}
	answer += one;
	if (minus.size() % 2 == 0)
	{
		for (int i = minus.size() - 1; i >0; i = i - 2)
		{
			answer += minus[i] * minus[i - 1];
		}
	}
	else
	{
		for (int i = minus.size() - 1; i >0; i = i - 2)
		{
			answer += minus[i] * minus[i - 1];
		}
		if (zero == 0)
		{
			answer -= minus[0];
		}
	}
	cout << answer << '\n';
}