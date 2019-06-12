#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string &u,string &v)
{
	if(u.size()<v.size())
	{
		return true;
	}
	else if(u.size()==v.size())
	{
		if(u.compare(v)==0)
		{
			return false;
		}
		else if(u.compare(v)<0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	int N;
	cin>>N;
	vector<string> word;
	for(int i=0; i<N; i++)
	{
		string S;
		cin>>S;
		word.push_back(S);
	}
	sort(word.begin(),word.end(),cmp);
	cout<<word[0]<<endl;
	for(int i=1; i<N; i++)
	{
		if(word[i]==word[i-1])
		{
			continue;
		}
		cout<<word[i]<<endl;
	}
	
}
