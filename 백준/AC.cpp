#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	for(int tn=0; tn<T; tn++)
	{
		string p;
		cin>>p;
		int n;
		cin>>n;
		vector<int> numb;
		string arr;
		cin>>arr;
		int asize=arr.size();
		int i=0;
		while(i<asize)
		{
			if(arr[i]=='[' || arr[i]==',')
			{
				int j=i+1;
				vector<int> temp;
				while(arr[j]!=']' && arr[j]!=',')
				{
					temp.push_back(arr[j]-'0');
					j++;
				}
				int tsize=temp.size();
				int number=0;
				for(int k=tsize-1; k>=0; k--)
				{
					number+=pow(10,tsize-1-k)*temp[k];
				}
				if(number)
				{
					numb.push_back(number);
				}
				i=j;
				if(i==asize-1)
				{
					break;
				}
			}
		}
		int start=0;
		int end=0;
		if(numb.size())
		{
			end=numb.size();
		}
		bool iserror=false;
		int psize=p.size();
		for(i=0; i<psize; i++)
		{
			if(p[i]=='R')
			{
				int temp=start;
				start=end;
				end=temp;
			}
			else if(p[i]=='D')
			{
				if(start==end)
				{
					iserror=true;
					break;
				}
				else if(start<end)
				{
					start=start+1;
				}
				else
				{
					start=start-1;
				}
			}
		}
		if(!iserror)
		{
			if(start<end)
			{
				cout<<"[";
				for(i=start; i<end; i++)
				{
					cout<<numb[i];
					if(i!=end-1)
					{
						cout<<",";
					}
				}
				cout<<"]\n";
			}
			else
			{
				cout<<"[";
				for(i=start-1; i>=end; i--)
				{
					cout<<numb[i];
					if(i!=end)
					{
						cout<<",";
					}
				}
				cout<<"]\n";
			}
		}
		else
		{
			cout<<"error"<<'\n';
		}
	}
}
