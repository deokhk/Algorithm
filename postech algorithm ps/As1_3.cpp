#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int numb;
		cin>>numb;
		if(numb<=8)//trivial case -> do manually.
		{
			switch(numb)
			{
				case 1: cout<<"0 0"<<'\n';
				break;
				case 2: cout<<"0 1"<<'\n';
				break;
				case 3: cout<<"1 1"<<'\n';
				break;
				case 4: cout<<"1 0"<<'\n';
				break;
				case 5: cout<<"1 -1"<<'\n';
				break;
				case 6: cout<<"0 -1"<<'\n';
				break;
				case 7: cout<<"-1 -1"<<'\n';
				break;
				case 8: cout<<"-1 0"<<'\n';
				break;
				
			}
		}
		else
		{
		int i=0;
		while(i*i<=numb)
		{
			i++;
		}
		if(i%2==1)
		{
			int orx=(i-1)/2;
			int ory=-1*orx+1;
			int start=(i-1)*(i-1);
			int move=0;
			while(start!=numb)
			{
				if(move==0)
				{
					ory--;
				}
				else if(1<=move && move<=i-1)
				{
					orx--;
				}
				else
				{
					ory++;
				}
				move++;
				start++;
			}
			cout<<orx<<" "<<ory<<'\n';
		}
		else
		{
			int orx=-1*(i-2)/2;
			int ory=-1*orx;
			int start=(i-1)*(i-1);
			int move=0;
			while(start!=numb)
			{
				if(move==0)
				{
					ory++;
				}
				else if(1<=move && move<=i-1)
				{
					orx++;
				}
				else
				{
					ory--;
				}
				move++;
				start++;
				
			}
			cout<<orx<<" "<<ory<<'\n';
		}
	    }
	}
}
