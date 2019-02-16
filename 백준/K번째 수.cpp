#include <iostream>
#include <algorithm>
using namespace std;
int sequence[5000006];
int main()
{
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	sort(sequence, sequence + n);
	printf("%d\n", sequence[k - 1]);
}