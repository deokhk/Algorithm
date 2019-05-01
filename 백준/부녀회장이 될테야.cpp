#include <iostream>
using namespace std;
int DP[15][15];
int main()
{
	int T;
	cin>>T;
	for(int i=0; i<15; i++)
	{
		for(int j=1; j<15; j++)
		{
			if(i==0)
			{
				DP[i][j]=j;
			}
			else
			{
				for(int k=1; k<=j; k++)
				{
					DP[i][j]+=DP[i-1][k];
				}
			}
		}
	}
	for(int tn=0; tn<T; tn++)
	{
		int k,n;
		cin>>k>>n;
		cout<<DP[k][n]<<endl;
	}
}
