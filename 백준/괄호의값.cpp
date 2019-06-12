#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
struct dt
{
	char paren;
	int posi;
};
int score[31];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	stack<dt> love;
	cin>>s;
	int ssize=s.size();
	int answer=0;
	for(int i=0; i<ssize; i++)
	{
		if(love.empty() || (s[i]=='(' || s[i]=='['))
		{
			dt temp={s[i],i};
			love.push(temp);
			continue;
		}
		
		if(s[i]==')')
		{
			if(love.top().paren=='(')
			{
				dt temp=love.top();
				love.pop();
				if(temp.posi==i-1)
				{
					score[i]=2;
				}
				else
				{
					int insidev=0;
					for(int pos=temp.posi; pos<i; pos++)
					{
						if(score[pos])
						{
							insidev+=score[pos];
							score[pos]=0;
						}
					}
					score[i]=2*insidev;
				}
			}
			else
			{
				dt temp={s[i],i};
				love.push(temp);
			}
		}
		else if(s[i]==']')
		{
			if(love.top().paren=='[')
			{
				dt temp=love.top();
				love.pop();
				if(temp.posi==i-1)
				{
					score[i]=3;
				}
				else
				{
					int insidev=0;
					for(int pos=temp.posi; pos<i; pos++)
					{
						if(score[pos])
						{
							insidev+=score[pos];
							score[pos]=0;
						}
					}
					score[i]=3*insidev;
				}
			}
			else
			{
				dt temp={s[i],i};
				love.push(temp);
			}
		}
	}
	for(int i=0; i<31; i++)
	{
		answer+=score[i];
	}
	if(!love.empty())
	{
		cout<<"0"<<'\n';
	}
	else
	{
		cout<<answer<<endl;
	}
	
}
