#include <iostream>
using namespace std;
int tri[503][503];
int maxt[503][503];
int calmax(int i, int j);
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
	maxt[1][0] = tri[0][0];
	int temp=calmax(n,0);
	for (int i = 0; i < n-1; i++)
	{
		if (calmax(n,i) <= calmax(n,i+1))
		{
			temp=maxt[n][i + 1];
		}
	}
	cout << temp << endl;
	return 0;

}
int calmax(int i, int j)//Ư�� �ٱ����� max�� ���(i��° �� j��° ������..)
{
	if (maxt[i][j] > 0)//�ٱ��� ���� ���
	{
		return maxt[i][j];
	}
	else
	{
		if (j == 0 )//ù ����
		{
			maxt[i][0] = calmax(i-1,0) + tri[i - 1][0];
			return maxt[i][j];
		}
		else if (j == i - 1)//������ ����
		{
			maxt[i][j] = calmax(i - 1, j - 1) + tri[i - 1][j];
			return maxt[i][j];
		}
		else //�߰�����
		{
			int templ = calmax(i-1,j-1) + tri[i-1][j];
			int tempr = calmax(i-1,j) + tri[i-1][j];
			if (templ > tempr)
			{
				maxt[i][j] = templ;
			}
			else
			{
				maxt[i][j] = tempr;
			}
			return maxt[i][j];
		}
		
	}
}