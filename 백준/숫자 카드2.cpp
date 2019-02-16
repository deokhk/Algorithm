#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
	scanf("%d", &N);
	vector<int> deck(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &deck[i]);
	}
	sort(deck.begin(), deck.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);
		auto p = equal_range(deck.begin(), deck.end(), temp);
		printf("%d ", p.second - p.first);
	}

}