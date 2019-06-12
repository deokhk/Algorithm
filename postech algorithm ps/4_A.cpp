#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct bid {
	long long int fee;
	int deadline;
};
bool cmp(bid &u, bid &v)
{
	if (u.deadline < v.deadline)
	{
		return true;
	}
	else if (u.deadline == v.deadline)
	{
		return u.fee < v.fee;
	}
	else
	{
		return false;
	}
}
bool operator<(bid u, bid v) {
	if (u.fee > v.fee)
	{
		return false;
	}
	else if (u.fee == v.fee)
	{
		return u.deadline > v.deadline;
	}
	else
	{
		return true;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int n;
		scanf("%d", &n);
		int lastday = 0;
		vector<bid> tstore;
		for (int i = 0; i < n; i++)
		{
			long long int tf;
			int td;
			scanf("%lld %d", &tf, &td);
			bid temp = { tf,td };
			lastday = td > lastday ? td : lastday;
			tstore.push_back(temp);
		}
		vector<int> isavailable(lastday+1);
		sort(tstore.begin(), tstore.end(), cmp);
		long long answer = 0;
		priority_queue<bid> mset;
		int vboundary = tstore.size() - 1;
		for (int i = lastday; i >= 1; i--)
		{
			while (vboundary>=0 && tstore[vboundary].deadline>=i)
			{
				mset.push(tstore[vboundary]);
				vboundary--;
			}
			if (!mset.empty())
			{
				bid tmp = mset.top();
				mset.pop();
				answer += tmp.fee;
			}
		}
		printf("%lld\n", answer);
	}
}