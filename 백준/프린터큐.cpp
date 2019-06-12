#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
struct dt
{
	int pos;
	int importance;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int N,M;
		cin>>N>>M;
		deque<dt> print;
		for(int i=0; i<N; i++)
		{
			int tmp;
			cin>>tmp;
			dt inside={i,tmp};
			print.push_back(inside);
		}
		int order=1;
		while(1)
		{
			dt temp=print.front();
			bool isbiggest=true;
			int dsize=print.size();
			for(int i=1; i<dsize; i++)
			{
				if(print[i].importance > temp.importance)
				{
					isbiggest=false;
					break;
				}
			}
			if(isbiggest)
			{
				print.pop_front();
				if(temp.pos==M)
				{
					cout<<order<<'\n';
					break;
				}
				order++;
			}
			else
			{
				print.pop_front();
				print.push_back(temp);
			}
		}
	}
	
}
