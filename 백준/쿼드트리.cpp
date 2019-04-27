#include <iostream>
using namespace std;
int qtree[65][65];
void ziptree(int size, int xcor, int ycor);
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%1d",&qtree[i][j]);
		}
	}
	ziptree(N,0,0);
	
}
void ziptree(int size, int xcor, int ycor)
{
	if(size==1)
	{
		printf("%d",qtree[xcor][ycor]);
	}
	else
	{
		int bezipped=1;
		for(int i=xcor; i<xcor+size; i++)
		{
			for(int j=ycor; j<ycor+size; j++)
		    {
		    	if(qtree[i][j]!=qtree[xcor][ycor])
		    	{
		    		bezipped=0;
		    		int adsize=size/2;
		    		printf("(");
					ziptree(adsize,xcor,ycor);
		    		ziptree(adsize,xcor,ycor+adsize);
		    		ziptree(adsize,xcor+adsize,ycor);
		   		ziptree(adsize,xcor+adsize,ycor+adsize);
		    		printf(")");
		    		break;
				}
			
		    }
		    if(!bezipped)
		    {
		    	break;
		    }
		}
		if(bezipped)
		{
			printf("%d",qtree[xcor][ycor]);
		}
		
	}
	
}
