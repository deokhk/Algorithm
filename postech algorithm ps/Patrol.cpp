#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
	int x;
	int y;
};
int DP[301][301];
int dist(point a, point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int mindist(vector<point> &patrol,int forward,int backward,int psize);
int main()
{
	int t;
	cin>>t;
	for(int tn=0; tn<t; tn++)
	{
		int N;
		cin>>N;
		vector<point> patrol(N);
		for(int i=0; i<N; i++)
		{
			int tx,ty;
			cin>>tx>>ty;
			point temp={tx,ty};
			patrol[i]=temp;
		}
		cout<<"hello";
		int answer=mindist(patrol,0,0,N);
		cout<<answer<<'\n';
		for(int i=0; i<301; i++)
		{
			for(int j=0; j<301; j++)
			{
				DP[i][j]=0;
			}
		}
	}
}
int mindist(vector<point> &patrol,int forward,int backward,int psize)
{
	if(DP[forward][backward])
	{
		return DP[forward][backward];
	}
	
	int mvalue=max(forward,backward);
	mvalue+=1;
	if(mvalue==psize-1)
	{
		return dist(patrol[forward],patrol[mvalue])+dist(patrol[backward],patrol[mvalue]);
	}
	
	int res=min(dist(patrol[forward],patrol[mvalue])+mindist(patrol,backward,mvalue,psize),dist(patrol[backward],patrol[mvalue])+mindist(patrol,forward,mvalue,psize));
	DP[forward][backward]=res;
	return res;
}
