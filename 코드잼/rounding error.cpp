#include <iostream>
#include <algorithm>
using namespace std;
int calban(int total, int group);//��ü ������� �� �׷�� ������� �ް� �� �������� �ݿø��ؼ� ������
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
		int c[100000];//c���� ������ �迭
		fill_n(c, n, 0);//C�迭�� �ʱ�ȭ
		for (int k = 0; k < l; k++)
		{
			cin >> c[k];
			total = total + c[k];
		}
		int rem = n - total;//�亯���� �ʰ� ���� ������� ��
		int arem = rem;
		float partial = 100.0 / float(n);//�� div�� ����
		int partialn = 100 / n;
		float frac = partial - partialn;//������.

		int newlcost = 0;//���ο� ��� �ݿø� ����� ����
		int io = 0;
		int tempo = ismore(n, io);//temp
		while (newlcost == tempo)
		{
			tempo=ismore(n, ++io);
		}
		newlcost = io;
		total = 0;
		if (frac >= 0.5)//���� ������� ���� �ٸ� �� �����ϴ°� ����Ʈ
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
		else if(frac==0)//frac�� 0�� ���. �� 
		{
			total = 100;
		}
		else//frac�� 0���� ũ�� 0.5���� ���� ���
		{
			int more[100000];//�� ���� �󸶳� ���� Ƚ���� �ʿ����� ������.
			fill_n(more, l, 0);//more�迭�� �ʱ�ȭ
			int d = 0;
			for (int k = 0; k < l; k++)
			{
				if (!ismore(n, c[k]))//���ڶ� ģ������ ����
				{
					int now = ismore(n, c[k]);//���� �׷��� calban���� ����
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
				if (1 <= more[k] && more[k] < newlcost)//���ο� �� ����ϴ� cost���� �������
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
int calban(int total,int group)//��ü ������� �� �׷�� ������� �ް� �� �������� �ݿø��ؼ� ������
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