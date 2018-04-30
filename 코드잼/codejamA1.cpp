#include <stdio.h>
#include <string.h>
int main(void)
{
	int t;
	char str[1001];
	int pan;
	int len;
	int task=1;
	scanf("%d",&t);
	while(t--)
	{
		int possible=1;
		int count=0;
		scanf("%s", str);
		scanf("%d", &pan);
		len=strlen(str);
		for(int i=0; i<len; i++)
		{
			if(str[i]=='-')
			{
				for(int k=0;k<pan;k++) // 뒤집는 알고리
				{ 
					if(i+k<len && str[i+k]=='-')
					{str[i+k]='+';}
					else
					{str[i+k]='-';}
				}
				count++;
			}
		}
		for(int i=0; i<len; i++)
		{
			printf("변화된 첫줄\n"); 
			if(str[i]=='-')
			{
				possible=0;
				break;
			}
		}
		for(int i=0; i<len; i++)
		{
			if(str[i]=='-')
			{
				possible=0;
				break;
			}
		}
		if(possible==1)
		{printf("Case #%d: %d\n",task,count);}
		else
		{
			printf("Case #%d: IMPOSSIbLE\n",task);
		}
		task++;
	}
}

