#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(int &u, int &v);
int main()
{
	string num;
	cin >> num;
	int numsize = num.size();
	int zero = 0;
	int sum = 0;
	vector<int> three;
	for (int i = 0; i < numsize; i++)
	{
		int temp = num[i] - '0';
		if (temp == 0)
		{
			zero++;
		}
		three.push_back(temp);
		sum += temp;
	}
	if (!zero || sum%3!=0)
	{
		cout << "-1" << '\n';
	}
	else
	{
		sort(three.begin(), three.end(), cmp);
		for (int i = 0; i < numsize; i++)
		{
			num[i] = three[i] + '0';
		}
		cout << num << '\n';
	}
}
bool cmp(int &u, int &v)
{
	return u > v;
}