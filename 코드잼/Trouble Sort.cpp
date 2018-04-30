#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
void TroubleSort(int arr[],int size);
int num[100001];
int odd[50001];
int even[50001];
int main(void)
{
	int t;
	scanf("%d", &t);
	int casecount=0;
	while(t--)
	{
		int leng;
		int error;
		bool complete=true;
		scanf("%d", &leng);
		for(int i=0; i<leng; i++)
		{
			scanf("%d", &num[i]);
			if(i%2!=0)
			{
				even[i/2]=num[i];
			}
			else
			{
				odd[i/2]=num[i];
			}
		}
		sort(num,num+(leng-1));
		int newnum=leng/2;
		if(leng%2==0)
		{
		TroubleSort(odd,newnum);
		TroubleSort(even,newnum);
		}
		else
		{
		TroubleSort(odd,newnum+1);
		TroubleSort(even,newnum);
		}
		for(int i=0; i<leng; i++)
		{
			if(i%2==0)
			{
				if(num[i]!=odd[i/2])
				{
					error=i;
					complete=false;
					break;
				}
			}
			else
			{
				if(num[i]!=even[i/2])
				{
					error=i;
					complete=false;
					break;
				}
			}
		}
		casecount++;
		if(complete)
		{
			cout<<"Case #"<<casecount<<": OK"<<endl;
		}
		else
		{
			cout<<"Case #"<<casecount<<": "<<error<<endl;
		}
	}
}
void TroubleSort(int arr[],int len)
{
	bool done=false;
	while(!done)
	{
		done=true;
		for(int i=0; i<len-2; i++)
		{
			if(arr[i] >arr[i+2])
			{
				done=false;
				int temp=arr[i];
				arr[i]=arr[i+2];
				arr[i+2]=temp;
			}
		}
	}
}
