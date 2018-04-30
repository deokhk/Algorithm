#include <stdio.h>
#include <string.h>
int main(void)
{
	int n;
	char s[104]={0};
	int diversity=1;
	bool possible=true;
	int i,j;
	scanf("%d", &n);
	scanf("%s",s);
	for(i=0;i<n; i++)
	{
		if(s[i]=='?')
		{
			j=i;
			int count=0;
			while(s[j] &&(s[j]=='?'))
			{
				j++;
				count++;
			}
			if(count==1)
			{
				if(i==0 || i==n-1)
				{
					diversity=2;
				}//1개는 안되는 경우가 없음. 
				else if(s[i-1]==s[i+1])
				{
					diversity=2;
				}
			}
			else 
			{
				diversity=2;
			}
			i=i+count-1;
		}
		else
		{
			if(s[i]==s[i+1])
			{
				possible=false;
				break;
			}
		}
	}
	if(possible && diversity==2)
	{
		printf("yes\n");
	}
	else
	{
		printf("No\n");
	}
}
