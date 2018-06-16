#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		bool isprime = true;
		for (int j = 2; j < temp; j++)
		{
			if (temp%j == 0)
			{
				isprime = false;
				break;
			}
		}
		if (isprime && temp != 1)
		{
			num++;
		}
	}
	cout << num << endl;

}