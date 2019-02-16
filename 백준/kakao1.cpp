#include <iostream>
int contest[1005][2];
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> contest[i][0] >> contest[i][1];
		int answer = 0;
		if (contest[i][0])
		{
			int r = contest[i][0];
			if (r == 1)
			{
				answer += 500;
			}
			else if (r <= 3)
			{
				answer += 300;
			}
			else if (r <= 6)
			{
				answer += 200;
			}
			else if (r <= 10)
			{
				answer += 50;
			}
			else if (r <= 15)
			{
				answer += 30;
			}
			else if (r <= 21)
			{
				answer += 10;
			}
		}
		if (contest[i][1])
		{
			int r = contest[i][1];
			if (r == 1)
			{
				answer += 512;
			}
			else if (r <= 3)
			{
				answer += 256;
			}
			else if (r <= 7)
			{
				answer += 128;
			}
			else if (r <= 15)
			{
				answer += 64;
			}
			else if (r <= 31)
			{
				answer += 32;
			}
		}
		cout << answer * 10000 << '\n';
	}

}