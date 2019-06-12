#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct seg
{
	long long left;
	long long right;
	long long y;
};
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int n, w;
		scanf("%d %d", &n, &w);
		vector<seg> house;
		for (int i = 0; i < n; i++)
		{
			long long tl, tr, ty;
			scanf("%lld %lld %lld", &tl, &tr, &ty);
			seg tmp = { tl,tr,ty };
			house.push_back(tmp);
		}
		stack<int> st;
		long long marea = 0;
		long long now = 0;
		vector<long long> nowarray;
		for (int i = 0; i < n; i++)
		{
			nowarray.push_back(now);
			now = now + (house[i].right - house[i].left);
		}
		nowarray.push_back(now);
		int idx = 0;
		while (idx<n)
		{
			if (st.empty() || house[st.top()].y <= house[idx].y)
			{
				st.push(idx);
				idx++;
			}
			else
			{
				int tidx = st.top();
				long long tarea = 0;
				st.pop();
				if (st.empty())
				{
					tarea = house[tidx].y * nowarray[idx];
				}
				else
				{
					long long topprev = st.top();
					tarea = house[tidx].y * (nowarray[idx] - nowarray[topprev+1]);
				}
				marea = marea < tarea ? tarea : marea;
			}

		}
		while (!st.empty())
		{
			int tidx = st.top();
			long long tarea = 0;
			st.pop();
			if (st.empty())
			{
				tarea = house[tidx].y * nowarray[idx];
			}
			else
			{
				long long topprev = st.top();
				tarea = house[tidx].y * (nowarray[idx] - nowarray[topprev+1]);
			}
			marea = marea < tarea ? tarea : marea;
		}
		printf("%lld\n", marea);
	}
}