#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int ssize=1;
	int totalcost=0;
	string s;
	cin>>s;
	set<string> S;
	S.insert(s);
	while(ssize<k)
	{
		set<string> nS;
		bool ispossible=true;
		for(auto iter=S.begin(); iter!=S.end(); ++iter)
		{
			string temp=*iter;
			if(temp.size()==0)
			{
				ispossible=false;
				break;
			}
			int tsize=temp.size();
			for(int i=0; i<tsize; i++)
			{
				string nstr=temp.substr(0,i)+temp.substr(i+1,tsize-1);
				int oldsize=nS.size();
				nS.insert(nstr);
				int newsize=nS.size();
				if(newsize>oldsize)
				{
					ssize++;
					totalcost+=(n-(tsize-1));
					if(ssize>=k)
					{
						break;
					}
				}
				
			}
			if(ssize>=k)
			{
				break;
			}
		}
		S.swap(nS);
		if(!ispossible)
		{
			break;
		}
	}
	if(ssize<k)
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<totalcost<<'\n';
	}
}
