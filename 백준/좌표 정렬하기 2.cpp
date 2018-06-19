#include <iostream>
#include <algorithm>
#include <vector>
struct Point
{
	int x, y;
};
bool cmp(const Point &u, const Point &v);
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<Point> pos(N);
	for (int i = 0; i < pos.size(); i++)
	{
		scanf("%d", &pos[i].x);
		scanf("%d", &pos[i].y);
	}
	sort(pos.begin(), pos.end(), cmp);
	for (int i = 0; i < pos.size(); i++)
	{
		printf("%d %d\n", pos[i].x, pos[i].y);
	}
}
bool cmp(const Point &u, const Point &v)
{
	if (u.y < v.y)
	{
		return true;
	}
	else if (u.y == v.y)
	{
		return u.x < v.x;
	}
	else
	{
		return false;
	}
}