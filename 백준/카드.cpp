#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int card[1000005];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin>>card[i];
	}
	sort(card, card + N);
	vector<pair<int,long long int>> cardcount;
	cardcount.push_back(make_pair(1, -1*card[0]));
	int j = 0;
	for (int i = 1; i < N; i++)
	{
		if (-1*cardcount[j].second == card[i])
		{
			cardcount[j].first++;
		}
		else
		{
			cardcount.push_back(make_pair(1, -1*card[i]));
			j++;
		}
	}
	sort(cardcount.begin(), cardcount.end());
	int csize = cardcount.size();
	long long int ans = -1 * cardcount[csize - 1].second;
	cout << ans << endl;
}
