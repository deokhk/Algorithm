#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Point {
	int coorx;
	int coory;
};
Point points[1000003];
bool cmp(const Point &i,const Point &j);
void angular_quick_sort(int left, int right);
int main()
{
	int t;
	scanf("%d", &t);
	srand(time(NULL));
	for (int tn = 0; tn<t; tn++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j<N; j++)
		{
			scanf("%d", &points[j].coorx);
			scanf("%d", &points[j].coory);
		}
		angular_quick_sort(0, N-1);
		for (int i = 0; i<N; i++)
		{
			printf("%d %d \n", points[i].coorx, points[i].coory);
		}
		printf("\n");
	}
}
void angular_quick_sort(int left, int right)
{
	if(right > left)
	{
	int i = left;
	int j = right+1;
	int pivot=left+rand()%(j-i);
	Point temp=points[left];
	points[left]=points[pivot];
	points[pivot]=temp;
	while(i<j)
	{
		do
		{
			i++;
		}while(i<=right && !cmp(points[left],points[i]));
		do
		{
			j--;
		}while(j>=left+1 && cmp(points[left],points[j]));
		if(i<j)
		{
			Point temp=points[i];
			points[i]=points[j];
			points[j]=temp;
		}
	}
	temp=points[left];
	points[left]=points[j];
	points[j]=temp;
	angular_quick_sort(left, j - 1);
	angular_quick_sort(j + 1, right);
	}
	else
	{
		return;
	}
}
bool cmp(const Point &i,const Point &j)
{
	int iqd=0;
	int jqd=0;
	if(i.coorx>=0 && i.coory>0)
	{
		iqd=1;
	}
	else if(i.coorx>0 && i.coory<=0)
	{
		iqd=2;
	}
	else if(i.coorx<=0 && i.coory<=0)
	{
		iqd=3;
	}
	else
	{
		iqd=4;
	}
	
	if(j.coorx>=0 && j.coory>0)
	{
		jqd=1;
	}
	else if(j.coorx>0 && j.coory<=0)
	{
		jqd=2;
	}
	else if(j.coorx<=0 && j.coory<=0)
	{
		jqd=3;
	}
	else
	{
		jqd=4;
	}
	if(jqd>iqd)
	{
		return true;
	}
	else if(jqd<iqd)
	{
		return false;
	}
	else
	{
		if(jqd==1)
		{
			if(i.coorx==0 && j.coorx==0)
			{
				return j.coory>i.coory;
			}
			else if(i.coorx==0 || j.coorx==0)
			{
				return j.coorx>i.coorx;
			}
			else
			{
				double inci=(double)i.coory/i.coorx;
				double incj=(double)j.coory/j.coorx;
				if(inci==incj)
				{
					return j.coorx>i.coorx;
				}
				else
				{
					return incj<inci;
				}
			}
		}
		else if(jqd==2)
		{
			if(i.coory==0 && j.coory==0)
			{
				return j.coorx>i.coorx;
			}
			else if(i.coory==0 || j.coory==0)
			{
				return j.coory<i.coory;
			}
			else
			{
				double inci=(double)i.coory/i.coorx;
				double incj=(double)j.coory/j.coorx;
				if(inci==incj)
				{
					return j.coorx>i.coorx;
				}
				else
				{
					return incj<inci;
				}
			}
			
		}
		else if(jqd==3)
		{
			if(i.coorx==0 && j.coorx==0)
			{
				return j.coory<i.coory;
			}
			else if(i.coorx==0 || j.coorx==0)
			{
				return j.coorx<i.coorx;
			}
			else
			{
				double inci=(double)i.coory/i.coorx;
				double incj=(double)j.coory/j.coorx;
				if(inci==incj)
				{
					return j.coorx<i.coorx;
				}
				else
				{
					return incj<inci;
				}
			}
		}
		else
		{
			if(i.coory==0 && j.coory==0)
			{
				return j.coorx<i.coorx;
			}
			else if(i.coory==0 || j.coory==0)
			{
				return j.coory>i.coory;
			}
			else
			{
				double inci=(double)i.coory/i.coorx;
				double incj=(double)j.coory/j.coorx;
				if(inci==incj)
				{
					return j.coorx<i.coorx;
				}
				else
				{
					return incj<inci;
				}
			}
		}
	}
}
