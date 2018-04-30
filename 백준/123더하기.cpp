#include <iostream>
using namespace std;
int way[10];
int how(int z);
int main()
{
	int t;
	way[1] = 1;
	way[2] = 2;
	way[3] = 4;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << how(n) << endl;
	}
}
int how(int z)
{
	if (way[z] > 0)
		return way[z];
	else
	{
		way[z] = how(z - 1) + how(z - 2) + how(z - 3);
		return way[z];
	}
}