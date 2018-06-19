#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int number[10005];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		number[temp]++;
	}
	for (int i = 0; i <=10000; i++)
	{
		if (number[i] > 0)
		{
			int repeat = number[i];
			for (int j = 0; j < repeat; j++)
			{
				printf("%d\n", i);
			}
		}
	}
}