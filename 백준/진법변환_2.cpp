#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	int N, B;
	stack<char> converted;
	cin >> N >> B;
	while (N != 0)
	{
		int temp = N%B;
		char tempc;
		if (temp < 10)
		{
			tempc = temp + '0';
		}
		else
		{
			tempc = temp - 10 + 'A';
		}
		converted.push(tempc);
		N /= B;
	}
	while (!converted.empty())
	{
		cout << converted.top();
		converted.pop();
	}

}