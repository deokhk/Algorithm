#include <iostream>
using namespace std;
int tri[501][501];
int max[501];
int pos[501];
int calmax(int rown);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}
	max[1] = tri[0][0];
	pos[1] = 0;//tri�迭������ j pos�� �ǹ�
	int max = calmax(n);
	cout << max << endl;

}
int calmax(int rown)//Ư�� �ٱ����� max�� ���
{
	if (max[rown] > 0)//�ٱ��� ���� ���
	{
		return max[rown];
	}
	else
	{
		int templ = calmax(rown - 1) + tri[rown - 2][pos[rown - 1]];
		int tempr = calmax(rown - 1) + tri[rown - 2][pos[rown - 1] + 1];
		if (templ > tempr)
		{
			max[rown] = templ;
			pos[rown] = pos[rown - 1];
		}
		else
		{
			max[rown] = tempr;
			pos[rown] = pos[rown - 1]+1;
		}
		return max[rown];
	}
}