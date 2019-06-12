#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn<t; tn++)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		vector<long long> narr(n);
		vector<long long> marr(m);
		long long ans = 0;
		for (int i = 0; i<n; i++)
		{
			scanf("%lld", &narr[i]);
		}
		for (int i = 0; i<m; i++)
		{
			scanf("%lld", &marr[i]);
		}
		sort(narr.begin(), narr.end());
		sort(marr.begin(), marr.end());
		bool nanswer = true;
		int nr=0;
		int mr = m - 1;
		int pk = 0;
		if(k/m==0)
		{
			nr=0;
		}
		else if(k!=m*n)
		{
			nr=k/m;
		}
		else
		{
			nanswer=false;
			ans=narr[n-1]*marr[m-1];
		}
		while (nanswer)
		{
			long long pnum = narr[nr] * marr[mr];

			for (int i = m - 1; i >= 0; i--)
			{
				if (marr[i] * narr[0]>pnum)
				{
					pk++;
				}
				else
				{
					break;
				}
			}
			int l1num = m - pk;
			int tot = l1num;
			for (int i = 1; i<n; i++)
			{
				if (narr[i] * marr[m - 1]<pnum)
				{
					tot += m;
				}
				else
				{
					int temptot=tot;
					int linum = l1num*(narr[0]) / (narr[i]);
					for (int j = linum; j<m; j++)
					{
						if (narr[i] * marr[j] <= pnum)
						{
							tot++;
						}
						else
						{
							break;
						}
					}
					tot += linum;
					if(temptot==tot)
					{
						break;
					}
				}
			}
			printf("mr:%d,nr:%d,pnum:%d,tot:%d\n",mr,nr,pnum,tot);
			if (tot>k)
			{
				if (mr >= 1)
				{
					mr=mr/2;
				}
				else
				{
					nr--;
				}
			}
			else if (tot == k)
			{
				ans = marr[mr] * narr[nr];
				nanswer = false;
			}
			else
			{
				int newmr=mr+(mr/2);
				if(newmr<m-1)
				{
					if(newmr==0)
					{
						mr++;
					}
					else
					{
						mr=newmr;
					}
				}
				else if(mr==m-1)
				{
					nr++;
				}
				else
				{
					mr=((mr+m-1)/2)+1;
				}
				
			}
			pk = 0;
		}
		printf("%lld\n", ans);
	}
}


