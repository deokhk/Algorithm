#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double logB(double x, double base)
{
	return log(x) / log(base);
}
bool isprime(int x)
{
	bool pr = true;
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
		{
			pr = false;
		}
	}
	return pr;
}
int main()
{
	int K;
	cin >> K;
	int numofpower = 0;
	int i = 2;
	while(K>0)
	{
		if (K == 1)
		{
			break;
		}
		if (K%i == 0)
		{
			K=K/i;
			numofpower++;
		}
		else
		{
			i++;
		}
	}
	double answer = ceil(logB(numofpower, 2));
	printf("%0.lf\n", answer);
}