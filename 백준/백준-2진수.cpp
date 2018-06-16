#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int N;
	cin >> N;
	stack<int> mod;
	if (N == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	while (N != 0)
	{
		if (N > 0)
		{
			if (N % 2 == 0)
			{
				mod.push(0);
				N = -(N / 2);
			}
			else
			{
				mod.push(1);
				N = -(N / 2);
			}
		}
		else
		{
			if (N % 2 == 0)
			{
				mod.push(0);
				N = -(N / 2);
			}
			else
			{
				mod.push(1);
				N = -(N / 2)+1;
			}
		}
	}
	while (!mod.empty())
	{
		int temp=mod.top();
		cout << temp;
		mod.pop();
	}
	return 0;
}