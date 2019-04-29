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
	int mininum=0;
	for(int i=0; i<mssize; i++)
	{
		if(massset[i]<0)
		{
			mininum++;
		}
	}
	vector<int> subconsum;
	int nextstart=0;
	int firstsum=0;
	int last=0;
	bool isfastpossible=false;
	int numofm=0;
    for(int i=0; i<mssize; i++)
    {
      if(massset[i]<0)
      {
        numofm++;
      }
    }
	//calculate subconsum 0
	if(numofm<=K)
	{
		cout<<N<<endl;
	}
	else
	{
		int fc=0;
	for(int i=0; i<mssize; i++)
	{
		firstsum+=abs(massset[i]);
		if(fc==1 && massset[i]>0)
		{
			nextstart=i;
		}
		if(massset[i]<0)
		{
			fc++;
		}
		if(fc==K && massset[i]>0)
		{
			last=i;
			break;
		}
	}
	subconsum.push_back(firstsum);
	int checker=0;
	while(subconsum.size()<mininum-K+1)
	{
		int newsum=subconsum.back();
		int mcount=0;
		for(int j=nextstart-1; j>=0; j--)
		{
			newsum-=abs(massset[j]);
			if(massset[j]<0)
			{
				mcount++;
			}
			if(mcount==1 && massset[j]>0)
			{
				break;
			}
		}
		mcount=0;
		nextstart+=2;
		for(int j=last+1; j<mssize; j++)
		{
			newsum+=abs(massset[j]);
			if(massset[j]<0)
			{
				mcount++;
			}
			if(mcount==1 && massset[j]>0)
			{
				last=j;
				break;
			}
		}
		subconsum.push_back(newsum);
	}
	
	sort(subconsum.begin(),subconsum.end());
	cout<<subconsum.back()<<endl;
	}
}
