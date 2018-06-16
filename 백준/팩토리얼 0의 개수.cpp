#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int twocount = 0;
	int fivecount = 0;
	int N;
	cin >> N;
	for (int i = N; i > 1; i--)
	{
		int j = i;
		while (j % 2 == 0)
		{
			twocount++;
			j /= 2;
		}
		while (j % 5 == 0)
		{
			fivecount++;
			j /= 5;
		}
	}
	int num = min(twocount, fivecount);
	cout << num << endl;

}