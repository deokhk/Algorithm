#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{	
	int N,K;
	string S;
	cin>>N>>K>>S;
	int mass=0;
	vector<int> massset;
	for(int i=0; i<N; i++)
	{
		if(mass==0)
		{
			if(S[i]=='0')
			{
				mass=-1*1;
			}
			else
			{
				mass=1;
			}
		}
		else if(mass<0 && S[i]=='1')
		{
			massset.push_back(mass);
			mass=1;
		}
		else if(mass>0 && S[i]=='0')
		{
			massset.push_back(mass);
			mass=-1*1;
		}
		else if(mass>0 && S[i]=='1')
		{
			mass++;
		}
		else if(mass <0 && S[i]=='0')
		{
			mass--;
		}
		
		if(i==N-1)
		{
			massset.push_back(mass);
		}
	}
	int mssize=massset.size();
	int consec=0;
	vector<int> cmpv;
	for(int i=0; i<2*K; i++)
	{
		if(i<mssize)
		{
			consec+=abs(massset[i]);
		}
	}
	cmpv.push_back(-1*consec);
	if(mssize<2*K)
	{
		
	}
	else
	{
		
	}
	for(int i=1; i<mssize-K; i++)
	{
		if(i+2*K-1>=mssize-K)
		{
			consec=consec+(abs(massset[mssize-K-1])-abs(massset[i-1]));
		}
		else
		{
			consec=consec+(abs(massset[i+2*K-1])-abs(massset[i-1]));
		}
		cmpv.push_back(-1*consec);
	}
	sort(cmpv.begin(),cmpv.end());
	cout<<-1*cmpv[0]<<endl;
}
