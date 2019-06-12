#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef struct point {
	double coorx;
	double coory;
}Point;
Point points[1000003];
Point ptemp[1000003];
bool cmp(int i,int pivot);
void merge(int l, int m, int h);
void angular_merge_sort(int l, int h);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn<t; tn++)
	{
		int N;
		scanf("%d", &N);
		for (int j = 0; j<N; j++)
		{
			scanf("%lf", &points[j].coorx);
			scanf("%lf", &points[j].coory);
		}
		angular_merge_sort(0, N - 1);
		for (int i = 0; i<N; i++)
		{
			printf("%lf %lf\n", points[i].coorx, points[i].coory);
		}
		printf("\n");
	}
}
void merge(int l, int m, int h)
{
	int i, l1, l2;
	for (i = l, l1 = l, l2 = m + 1; l1 <= m && l2 <= h; i++) 
	{
		if (cmp(l1,l2))
		{
			ptemp[i] = points[l1++];
		}
		else
		{
			ptemp[i] = points[l2++];
		}
	}
	while (l1 <=m)
	{
		ptemp[i++] = points[l1++];
	}
	while (l2 <= h)
	{
		ptemp[i++] = points[l2++];
	}
	for (i = l; i <= h; i++)
	{
		points[i] = ptemp[i];
	}
}
void angular_merge_sort(int l, int h)
{
	int m;
	if (l < h) 
	{
		m = (l + h) / 2;
		angular_merge_sort(l, m);
		angular_merge_sort(m + 1, h);
		merge(l, m, h);
	}
}
bool cmp(int i,int pivot)
{
    if (points[i].coorx>= 0 && points[pivot].coorx< 0)
    {
	    return true;
	}
    if (points[i].coorx< 0 && points[pivot].coorx>= 0)
    {
	    return false;
	}
    if (points[i].coorx== 0 && points[pivot].coorx== 0)
	{
        if (points[i].coory >= 0 || points[pivot].coory >= 0)
        {
		    return points[i].coory > points[pivot].coory;
		}
        return abs(points[pivot].coory) > abs(points[i].coory);
    }

    double direction = (points[i].coorx) * (points[pivot].coory) - (points[pivot].coorx) * (points[i].coory);
    if (direction < 0)
    {
	   return true;
	}
    else if (direction > 0)
    {
	    return false;
	}
	
    double di = (points[i].coorx) * (points[i].coorx) + (points[i].coory) * (points[i].coory);
    double dp = (points[pivot].coorx) * (points[pivot].coorx) + (points[pivot].coory) * (points[pivot].coory);
    return di < dp;
}

