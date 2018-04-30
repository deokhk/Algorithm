#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	s1 = s1 + s2;
	s3 = s3 + s4;
	int s1size = s1.size();
	int s3size = s3.size();
	long long x = 0;
	long long y = 0;
	for (int j = s1size; j > 0; j--)
	{
		x +=(s1[s1size-j]-'0')*pow(10, j - 1);
	}
	for (int k = s3size; k > 0; k--)
	{
		y+= (s3[s3size-k]-'0')*pow(10, k - 1);
	}
	x = x + y;
	cout << x;
}