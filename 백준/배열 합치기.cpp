#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int a, b;
	scanf("%d %d", &a,&b);
	vector<int> fir(a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &fir[i]);
	}
	for (int i = 0; i < b; i++)
	{
		int temp;
		scanf("%d", &temp);
		fir.push_back(temp);
	}
	sort(fir.begin(), fir.end());
	for (int i = 0; i < a + b; i++)
	{
		printf("%d ", fir[i]);
	}
}