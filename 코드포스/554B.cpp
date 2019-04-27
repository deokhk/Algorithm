#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isperfect(int x)
{
	while(x>0)
	{
		int mask=x&1;
		if(mask!=1)
		{
			return false;
		}
		x>>=1;
	}
	return true;
}
int zeroposition(int x)
{
	if (x == 0)
	{
		return 1;
	}
	int start = floor(log2(x));
	int answer = 0;
	for (int i = start; i > 0; i--)
	{
		if (x - pow(2, i) < pow(2, i - 1))
		{
			answer = i;
			break;
		}
		x = x - pow(2, i);
	}
	return answer;

}
int main()
{
	int x=0, input;
	cin >> x;
	input = x;
	bool tillend = true;
	int numofoperation = 0;
	vector<int> processing;
	while (tillend)
	{
		if (isperfect(x))
		{
			break;
		}
		if (numofoperation % 2 == 0)
		{
			int pos = zeroposition(x);
			processing.push_back(pos);
			pos = pow(2, pos) - 1;
			x = x ^ pos;
		}
		else
		{
			x = x + 1;
		}
		numofoperation++;
		if (numofoperation > 40)
		{
			break;
		}

	}
	cout << numofoperation << endl;
	for (int i = 0; i < processing.size(); i++)
	{
		cout << processing[i] << " ";
	}
}
