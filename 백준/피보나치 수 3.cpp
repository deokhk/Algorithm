#include <iostream>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long ans[2][2]={{1,0},{0,1}};
	long long mul[2][2]={{1,1},{1,0}};
	while(n>0)
	{
		long long now[2][2];
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				now[i][j]=mul[i][j];
			}
		}
		if(n%2==1)
		{
			long long temp[2][2];
			for(int i=0; i<2; i++)
			{
				for(int j=0; j<2; j++)
				{
					temp[i][j]=ans[i][j];
				}
			}
			for(int i=0; i<2; i++)
			{
				for(int j=0; j<2; j++)
				{
				
					ans[i][j]=0;
					for(int k=0; k<2; k++)
					{
						ans[i][j]+=(mul[i][k]*temp[k][j]);
					}
					ans[i][j]%=1000000;
					
				}
			}
		}
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				
				mul[i][j]=0;
				for(int k=0; k<2; k++)
				{
					mul[i][j]+=(now[i][k]*now[k][j]);
				}
				mul[i][j]%=1000000;
			}
		}
		n/=2; 
	}
	cout<<ans[0][1]<<endl;
}
