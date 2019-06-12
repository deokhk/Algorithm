#include <iostream>
using namespace std;
void matrixmult(long long int m[][2], long long int n[][2]);
int main()
{
	int t;
	scanf("%d",&t);
	for(int tn=0; tn<t; tn++)
	{
		int n;
		long long int ans;
		scanf("%d",&n);
		if(n==0)
		{
			printf("0\n");
		}
		else if(n==1)
		{
			printf("1\n");
		}
		else
		{
			long long int mat[2][2]={{1,0},{0,1}};
			long long int mul[2][2]={{1,1},{1,0}};
			while(n>0)
			{
				if(n%2==1)
				{
					matrixmult(mat,mul);
				}
				matrixmult(mul,mul);	
				n=n/2;
			}
			printf("%lld\n",mat[0][1]);
		}
	}
}
void matrixmult(long long int m[][2], long long int n[][2])
{
	long long int a=m[0][0]*n[0][0]+m[0][1]*n[1][0];
	long long int b=m[0][0]*n[0][1]+m[0][1]*n[1][1];
	long long int c=m[1][0]*n[0][0]+m[1][1]*n[1][0];
	long long int d=m[1][0]*n[0][1]+m[1][1]*n[1][1];
	
	m[0][0]=(a%2147483647);
	m[0][1]=(b%2147483647);
	m[1][0]=(c%2147483647);
	m[1][1]=(d%2147483647);


}
