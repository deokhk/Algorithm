#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int tn=0; tn<T; tn++)
	{
		int H,W,N;
		cin>>H>>W>>N;
		int ans=0; 
		if((N%H)==0)
		{
			int hori=(N/H);
			ans=100*H+hori;
		}
		else
		{
			int hori=(N/H)+1;
			int vert=N%H;
			ans=100*vert+hori;
		}
		cout<<ans<<endl;
	}
}
