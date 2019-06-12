#include <iostream>
#include <algorithm>
using namespace std;
int A[52][52];
int B[52][52];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<52; i++)
	{
		for(int j=0; j<52; j++)
		{
			A[i][j]=1000000004;
			B[i][j]=1000000004;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int temp;
			cin>>temp;
			A[i][j]=temp;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int temp;
			cin>>temp;
			B[i][j]=temp;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if((((A[i][j]>=A[i+1][j]) || (A[i][j]>=A[i][j+1])) || ((B[i][j]>=B[i+1][j]) || (B[i][j]>=B[i][j+1])))&&((B[i][j]<A[i+1][j] && B[i][j]<A[i][j+1]) && (A[i][j]<B[i+1][j] && A[i][j]<B[i][j+1])))
			{
				int temp=A[i][j];
				A[i][j]=B[i][j];
				B[i][j]=temp;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<'\n';
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<'\n';
	}
	bool ispossible=true;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if((A[i][j]>=A[i][j+1]) || (A[j][i]>=A[j+1][i]) || (B[i][j]>=B[i][j+1]) || (B[j][i]>=B[j+1][i]) )
			{
				ispossible=false;
				break;				
			}
		}
	}
	
	if(ispossible)
	{
		cout<<"Possible"<<'\n';
	}
	else
	{
		cout<<"Impossible"<<'\n';
	}
	
}
