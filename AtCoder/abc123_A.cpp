#include <iostream>
using namespace std;
int main()
{
	int antenna[5];
	int k;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &antenna[i]);
	}
	scanf("%d", &k);
	bool isconnected = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			if (antenna[j] - antenna[i] > k)
			{
				isconnected = false;
				break;
			}
		}
	}
	if (isconnected)
	{
		printf("Yay!");
	}
	else
	{
		printf(":(");
	}
}