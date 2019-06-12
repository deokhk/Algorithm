#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int N;
		scanf("%d", &N);
		vector<pair<int, int> > fishpoint(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &fishpoint[i].first, &fishpoint[i].second);

		}
		sort(fishpoint.begin(), fishpoint.end());
		int answer = 0;
		vector<int> track;
		for(int i=0; i<N; i++)
		{
			if(track.size()==0)
			{
				track.push_back(fishpoint[i].second);
				continue;
			}
			if(track.back()<=fishpoint[i].second)
			{
				track.push_back(fishpoint[i].second);
			}
			else
			{
				vector<int>::iterator it=lower_bound(track.begin(),track.end(),fishpoint[i].second);
				*it=fishpoint[i].second;
			}
		}
		answer=track.size();
		printf("%d\n", answer);
	}
}
