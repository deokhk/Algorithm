#include <iostream>
using namespace std;
int memo[1001][1001]; 
int main()
{
	int n,k;
	cin>>n>>k;
	memo[0][0]=1;
	for(int i=1; i<1001; i++)
	{
		memo[i][0]=1;
		for(int j=1; j<=i; j++)
		{
			memo[i][j]=(memo[i-1][j-1]+memo[i-1][j])%10007;
		}
	}
	cout<<memo[n][k]<<endl;
	
	
}
