#include <iostream>
using namespace std;
int A[10003];
int D[10003];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}
	D[1] = A[1];
	D[2] = A[1] + A[2];
	for (int i = 3; i <= n; i++)
	{
		D[i] = D[i - 1];
		if (D[i] < D[i - 2] + A[i])
		{
			D[i] = D[i - 2] + A[i];
		}
		if (D[i] < D[i - 3] + A[i - 1] + A[i])
		{
			D[i] = D[i - 3] + A[i - 1] + A[i];
		}
	}
	cout << D[n] << endl;

}