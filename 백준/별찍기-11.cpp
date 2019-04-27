#include <iostream>
#include <vector>
using namespace std;
bool find(vector<pair<int, int> > &star, int x, int y);
void draw(vector<vector<char > > &grid,vector<pair<int, int> > &star,int size, int x, int y);
int main()
{
	int N;
	cin >> N;
	vector<vector<char > > grid(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			grid[i].push_back(' ');
		}
	}
	vector<pair<int, int> > star;
	star.push_back(make_pair(0, 2));
	star.push_back(make_pair(1, 1));	
	star.push_back(make_pair(1, 3));
	star.push_back(make_pair(2, 0));
	star.push_back(make_pair(2, 1));
	star.push_back(make_pair(2, 2));
	star.push_back(make_pair(2, 3));
	star.push_back(make_pair(2, 4));
	draw(grid, star, N, 0, 0);
	for (int i = 0; i <  N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			cout<<grid[i][j];
		}
		cout << "\n";
	}
}
bool find(vector<pair<int, int> > &star, int x, int y)
{
	int vsize = star.size();
	bool isfind = false;
	for (int i = 0; i < vsize; i++)
	{
		pair<int, int> temp = star[i];
		if (temp.first == x && temp.second == y)
		{
			isfind = true;
			break;
		}
	}
	return isfind;
}
void draw(vector<vector<char > > &grid, vector<pair<int ,int> > &star,int size, int x, int y)
{
	if (size == 3)
	{
		for (int i = x; i < x+3; i++)
		{
			for (int j = y; j < y+6; j++)
			{
				if (find(star, i-x, j-y))
				{
					grid[i][j] = '*';
				}
				else
				{
					grid[i][j] = ' ';
				}
			}
		}
		return;
	}
	draw(grid, star, (size/2),x , y+(size/2));
	draw(grid, star, (size / 2), x+(size / 2), y);
	draw(grid, star, (size / 2), x+(size / 2), y+size);
}