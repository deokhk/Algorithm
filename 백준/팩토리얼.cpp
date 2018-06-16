#include <iostream>
using namespace std;
int calfact(int N);
int main()
{
	int N;
	cin >> N;
	int res = calfact(N);
	cout << res << endl;
}
int calfact(int N)
{
	if (N == 0)
	{
		return 1;
	}
	return N*calfact(N - 1);
}