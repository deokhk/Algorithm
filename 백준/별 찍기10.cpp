#include <iostream>
#include <vector>
using namespace std;
void draw(int x,int y, int n, vector<vector<char> > &grid);
int main()
{
	int N;
	cin >> N;
	vector<vector<char> > grid(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			grid[i].push_back(' ');
		}
	}
	draw(0,0,N,grid);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<<grid[i][j];
		}
		cout << "\n";
	}
}
void draw(int x,int y, int n, vector<vector<char> > &grid)
{
	if (n == 0)
	{
		grid[x][y] = '*';
		return;
	}
	draw(x,y,(n/3),grid);
	draw(x+(n/3),y,(n/3),grid);
	draw(x+2*(n/3),y,(n/3),grid);
	draw(x, y + (n / 3), (n / 3), grid);
	for (int i = x+(n/3); i < x+2*(n / 3); i++)
	{
		for (int j = y+(n/3); j < y+2*(n / 3); j++)
		{
			grid[i][j]=' ';
		}
	}
	draw(x+2*(n/3), y + (n / 3), (n / 3), grid);
	draw(x, y + 2*(n / 3), (n / 3), grid);
	draw(x+(n/3), y + 2*(n / 3), (n / 3), grid);
	draw(x+2*(n/3), y + 2*(n / 3), (n / 3), grid);

}