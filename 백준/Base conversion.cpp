#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
	int A, B, m;
	int base10 = 0;
	stack<int> res;
	cin >> A >> B >> m;
	for (int i = m-1; i >=0; i--)
	{
		int temp;
		cin >> temp;
		base10 += temp*pow(A, i);
	}
	while (base10 != 0)
	{
		res.push(base10%B);
		base10 /= B;
	}
	while (!res.empty())
	{
		int temp = res.top();
		res.pop();
		cout << temp<<" ";
	}
}