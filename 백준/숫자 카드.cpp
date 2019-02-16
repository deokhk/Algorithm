#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int deck[500001];
int bsearch(int x);
int N, M;
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&deck[i]);
	}
	sort(deck, deck + N);
    scanf("%d",&M);
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d",&temp);
		int exist = bsearch(temp);
		printf("%d ", exist);
	}

}
int bsearch(int x)
{
	int exist = 0;
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (deck[mid] == x)
		{
			exist = 1;
			break;
		}
		else if (deck[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return exist;
}