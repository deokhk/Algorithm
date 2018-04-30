#include <iostream>
#include <algorithm>
using namespace std;
int calban(int total, int group);//전체 사람수와 각 그룹당 사람수를 받고 그 차지값을 반올림해서 돌려줌
int ismore(int total, int group);
int main()
{
	int t;
	int i = 1;
	cin >> t;
	while (t--)
	{
		int total = 0;
		int n, l;
		cin >> n >> l;
		int c[100000];//c값을 저장할 배열
		fill_n(c, n, 0);//C배열을 초기화
		for (int k = 0; k < l; k++)
		{
			cin >> c[k];
			total = total + c[k];
		}
		int rem = n - total;//답변하지 않고 남은 사람들의 수
		int arem = rem;
		float partial = 100.0 / float(n);//각 div당 비율
		int partialn = 100 / n;
		float frac = partial - partialn;//남은거.

		int newlcost = 0;//새로운 언어 반올림 사람수 저장
		int io = 0;
		int tempo = ismore(n, io);//temp
		while (newlcost == tempo)
		{
			tempo=ismore(n, ++io);
		}
		newlcost = io;
		total = 0;
		if (frac >= 0.5)//남은 사람수를 각각 다른 언어에 배팅하는게 베스트
		{
			for (int j = 0; j < l; j++)
			{
				total = total + calban(n, c[j]);
			}
			for (int j = 0; j < rem; j++)
			{
				total = total + calban(n, 1);
			}
		}
		else if(frac==0)//frac이 0인 경우. 즉 
		{
			total = 100;
		}
		else//frac이 0보다 크고 0.5보다 작은 경우
		{
			int more[100000];//각 언어당 얼마나 많은 횟수가 필요한지 보여줌.
			fill_n(more, l, 0);//more배열을 초기화
			int d = 0;
			for (int k = 0; k < l; k++)
			{
				if (!ismore(n, c[k]))//모자란 친구들의 모임
				{
					int now = ismore(n, c[k]);//현재 그룹의 calban값을 저장
					int i = 0;
					int temp = ismore(n, c[k]);//temp
					while (now == temp)
					{
						i++;
						temp=ismore(n, c[k] + i);
					}
					more[d] = i;
					d++;
				}
			}
			sort(more, more + d);
			int add = 0;
			for (int k = 0; k < d; k++)
			{
				if (1 <= more[k] && more[k] < newlcost)//새로운 언어를 계산하는 cost보다 작은경우
				{
					rem = rem - more[k];
					if (rem <0)
					{
						rem = rem + more[k];
						break;
					}
					add++;
				}
			}
			while (rem >= 0)
			{
				rem = rem - newlcost;
				add++;
			}
			add = add - 1;
			for (int k = 0; k < l; k++)
			{
				total = total + calban(n, c[k]);
			}
			float h = calban(n, 1);
			h = arem*h;
			total = total+h+add;

		}
		cout << "Case #" << i << ": " <<total << endl;
		i++;
	}
	return 0;
}
int calban(int total,int group)//전체 사람수와 각 그룹당 사람수를 받고 그 차지값을 반올림해서 돌려줌
{
	float div = 100.0 / float(total);
	float groupsum = div*(float)group;
	int groupsumn = (int)groupsum;
	float frac = groupsum - groupsumn;
	if (frac >= 0.5)
	{
		int res = groupsum + 1;
		return res;
	}
	else
	{
		int res = groupsum;
		return res;
	}
}
int ismore(int total, int group)
{
	float div = 100.0 / float(total);
	float groupsum = div*(float)group;
	int groupsumn = (int)groupsum;
	float frac = groupsum - groupsumn;
	if (frac >= 0.5)
	{
		int res = 1;
		return res;
	}
	else
	{
		int res = 0;
		return res;
	}
	
}