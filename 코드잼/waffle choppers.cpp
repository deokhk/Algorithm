#include <iostream>
using namespace std;
char plate[150][150];
int main()
{
	int t,r,c,h,v;
	int testcase=0;
	cin>>t;
	while(t--)
	{
		cin>>r>>c>>h>>v;
		int chocochip=0;
		int rowcount=0;
		int colcount=0;
		int chocorow[150]={0};
		int chococol[150]={0};
		bool possible=true;
		for(int i=1;i<r+1;i++)
		{
			for(int j=1;j<c+1;j++)
			{
				cin>>plate[i][j];
				if(plate[i][j]=='@')
				{
					chocochip++;
					chocorow[i]++;
				}
			}
		}
		for(int i=1;i<c+1;i++)
		{
			for(int j=1;j<r+1;j++)
			{
				if(plate[j][i]=='@')
				{
					chococol[i]++;
				}
			}
		}
		if(chocochip%(h+1)==0 && chocochip%(v+1)==0)
		{
			int rowchoco=chocochip/(h+1);
			int rowpossible=0;
			int possiblerowset[h+1]={0};
			for(int i=1;i<r+1;i++)
			{
				rowcount=rowcount+chocorow[i];
				if(rowchoco==rowcount)
				{
					possiblerowset[rowpossible]=i;
					rowcount=0;
					rowpossible++;
				}
			}
			int colchoco=chocochip/(v+1);
			int colpossible=0;
			int possiblecolset[v+1]={0};
			for(int j=1; j<c+1;j++)
			{
				colcount=colcount+chococol[j];
				if(colchoco==colcount)
				{
					possiblecolset[colpossible]=j;
					colcount=0;
					colpossible++;
				}
			}
			if(rowpossible==h+1 && colpossible==v+1)
			{
				possible=true;
			}
			else
			{
				possible=false;
			}
			int sum[rowpossible*colpossible];
			fill_n(sum,rowpossible*colpossible,0);
			int d=0;
			for(int i=0; i<rowpossible;i++)
			{
				for(int j=0; j<colpossible;j++)
				{
					for(int k=(i==0) ? 0:possiblerowset[i-1]; k<=possiblerowset[i];k++)
					{
						for(int l=(j==0) ? 0:possiblecolset[j-1]; l<=possiblecolset[j];l++)
						{
							if(plate[k][l]=='@')
							{
								sum[d]++;
							}
						}
					}
					d++;
				}
			}
			int temp=0;
			for(int i=0; i<rowpossible*colpossible-1; i++)
			{
				if(sum[i]!=sum[i+1])
				{
					possible=false;
					break;
				}
			}
    	}
		else
		{
			possible=false;
		}
		if(chocochip==0)
		{
			possible=true;
		}
		testcase++;
		if(possible)
		{
			cout<<"Case #"<<testcase<<": POSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<testcase<<": IMPOSSIBLE"<<endl;
		}
	}

}
