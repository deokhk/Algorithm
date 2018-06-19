#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<pair<int,int>> pos;
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int tempx, tempy;
		scanf("%d",&tempx);
		scanf("%d", &tempy);
		pos.push_back(make_pair(tempx, tempy));
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n",pos[i].first,pos[i].second);
	}
}