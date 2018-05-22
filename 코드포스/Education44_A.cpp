#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int black = 0;
	int white = 0;
	vector<int> board;
	cin >> n;
	int temp;
	for (int i = 0; i < n / 2; i++)
	{
		cin >> temp;
		board.push_back(temp);
	}
	sort(board.begin(), board.end());
	for (int i = n / 2 - 1; i >= 0; i--)//relocate all pieces in black
	{
		int temp = abs((2 * i + 1) - board[i]);
		black = black + temp;

	}
	for (int i = n / 2 - 1; i >= 0; i--)//relocate all pieces in white
	{
		int temp = abs((2 * i + 2) - board[i]);
		white = white + temp;
	}
	int result = black > white ? white : black;
	cout << result << endl;
}