#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b)
{
	int tmp,n;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0)
	{
		n=a%b;
		a=b;
		b=n;
	}
	return a;
}
int main()
{
	int N;
	cin>>N;
	vector<int> board(N);
	for(int i=0; i<N; i++)
	{
		cin>>board[i];
	}
	vector<int> left(N);
	vector<int> right(N);
	left[0]=board[0];
	right[N-1]=board[N-1];
	for(int i=1; i<N; i++)
	{
		left[i]=gcd(left[i-1],board[i]);
	}
	for(int i=N-2; i>=0; i--)
	{
		right[i]=gcd(right[i+1],board[i]);
	}
	int gm=-1;
	for(int i=0; i<N; i++)
	{
		int nowgcd=0;
		if(i==0)
		{
			nowgcd=right[1];
		}
		else if(i==N-1)
		{
			nowgcd=left[N-2];
		}
		else
		{
		 	nowgcd=gcd(left[i-1],right[i+1]);	
		}
		gm=max(gm,nowgcd);
	}
	cout<<gm<<endl;
}
