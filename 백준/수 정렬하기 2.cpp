#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<int> sequence;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		sequence.push_back(temp);
	}
	sort(sequence.begin(), sequence.end());
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", sequence[i]);
	}

	

}