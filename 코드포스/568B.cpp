#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		string ts,tt;
		cin>>ts>>tt;
		//check validaty
		bool ispossible=true;
		int curs=0;
		int curt=0;
		int ssize=ts.size();
		int tsize=tt.size();
		vector<bool> issused(ssize);
		for(int i=0; i<ssize; i++)
		{
			issused[i]=false;
		}
		while(curt<tsize)
		{
			if(ts[curs]==tt[curt])
			{
				issused[curs]=true;
				curs++;
			}
			else
			{
				if(curs==0)
				{
					ispossible=false;
					break;
				}
				else if(curs!=0 && ts[curs-1]!=tt[curt])
				{
					ispossible=false;
					break;
				}
			}
			curt++;
		}
		for(int i=0; i<ssize; i++)
		{
			if(issused[i]==false)
			{
				ispossible=false;
				break;
			}
		}
		if(ispossible)
		{
			cout<<"YES"<<'\n';
		}
		else
		{
			cout<<"NO"<<'\n';
		}
	}
}
