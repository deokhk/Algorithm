#include <iostream>
using namespace std;
int in[100001];
int pos[100001];
void pre(int ins,int ind,int poss,int posd)
{
	//find node
	if(ins > ind || poss > posd)
	{
		return;
	}
	int node=pos[posd];
	cout<<node<<" ";
	int leftnum=0;
	for(int st=ins; st<=ind; st++)
	{
		if(in[st]==node)
		{
			break;
		}
		leftnum++;
	}
	pre(ins,ins+leftnum-1,poss,poss+leftnum-1);
	pre(ins+leftnum+1,ind,poss+leftnum,posd-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>in[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>pos[i];
	}
	pre(0,n-1,0,n-1);
}
