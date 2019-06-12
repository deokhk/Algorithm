#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[502][502];
int DP[502][502];
int way(int x,int y)
{
    if(DP[x][y]==-1)
    {
    	int dx[4]={-1,0,1,0};
    	int dy[4]={0,1,0,-1};
    	DP[x][y]=0;
    	for(int i=0; i<4; i++)
        {
		if(map[x][y]<map[x+dx[i]][y+dy[i]])
        {
        	if(DP[x+dx[i]][y+dy[i]]!=-1)
        	{
        		DP[x][y]+=DP[x+dx[i]][y+dy[i]];
        	}
        	else
        	{
        		DP[x][y]+=way(x+dx[i],y+dy[i]);
        	}
        }
		}
        return DP[x][y];
    }
    else
    {
        return DP[x][y];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    for(int i=0; i<502; i++)
    {
    	for(int j=0; j<502; j++)
    	{
    		DP[i][j]=-1;
    	}
    }
    DP[1][1]=1;
    if(m==1 && n==1)
	{
		cout<<0<<'\n';
		return 0;
	}
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>map[i][j];
        }
    }
    cout<<way(m,n)<<'\n';
}
