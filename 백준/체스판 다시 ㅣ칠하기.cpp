#include <iostream>
#include <string>
using namespace std;
char board[51][51];
char Wboard[8][8]={{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'}};
char Bboard[8][8]={{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'}};
int main()
{
	int N,M;
	cin>>N>>M;
	int min=32;
	for(int i=0; i<N; i++)
	{
		string mystring;
		cin>>mystring;
		for(int j=0; j<M; j++)
		{
			board[i][j]=mystring[j];
		}
	}
	for(int i=0; i<=N-8; i++)
	{
		for(int j=0; j<=M-8; j++)
		{
			int wmin=0;
			int bmin=0;
			for(int k=i; k<i+8; k++)
			{
				for(int l=j; l<j+8; l++)
				{
					if(board[k][l]!=Wboard[k-i][l-j])
					{
						wmin++;
					}
					if(board[k][l]!=Bboard[k-i][l-j])
					{
						bmin++;
					}
				}
			}
			if(min>wmin || min>bmin)
			{
				min=(wmin<bmin) ? wmin:bmin;
			}
		}
	}
	cout<<min;
	
}
