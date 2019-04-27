#include <iostream>
#include <cmath>
using namespace std;
int N, r, c;
int answer = 0;
int realanswer;
void visit(int size,int cx,int cy);
int main()
{
	cin >> N >> r >> c;
	visit(N,0,0);
	cout << answer<<"\n";
}
void visit(int size, int cx, int cy)
{
	if (size == 0)
	{
		if (cx == r && cy == c)
		{
			realanswer = answer;
		}
		return;
	}
	int dropcase = 0;
	if ((cx<=r &&r<cx+pow(2,size-1)) && (cy <= c &&c<cy + pow(2, size-1)))
	{
		dropcase = 0;
	}
	else if ((cx <= r &&r<cx + pow(2,size-1)) && (cy+pow(2,size-1) <= c ))
	{
		dropcase = 1;
	}
	else if ((cx + pow(2, size-1) <= r) && (cy <= c &&c<cy + pow(2, size-1)))
	{
		dropcase = 2;
	}
	else
	{
		dropcase = 3;
	}
	if (dropcase == 0)
	{
		visit(size-1, cx, cy);
	}
	else if (dropcase == 1)
	{
		answer += pow(2.0, size-1)*pow(2, size-1);
		visit(size-1, cx, cy + pow(2,size-1));
	}
	else if (dropcase == 2)
	{
		answer += 2*pow(2, size-1)*pow(2, size-1);
		visit(size-1, cx + pow(2,size-1), cy);
	}
	else
	{
		answer += 3*pow(2, size-1)*pow(2,size-1);
		visit(size-1, cx + pow(2,size-1), cy + pow(2,size-1));
	}
}