#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> hotel;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		hotel.push_back(temp);
	}
	int answer = 0;
	for (int i = 1; i < n ; i++)
	{
		if (hotel[i] - hotel[i - 1] == 2 * d)
		{
			answer += 1;
		}
		else if (hotel[i] - hotel[i - 1] > 2 * d)
		{
			answer += 2;
		}
	}
	answer = answer + 2;
	cout << answer << '\n';
}