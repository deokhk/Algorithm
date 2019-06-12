#include <iostream>
#include <string>
using namespace std;
char field[503][503];
int main()
{
	int h,w;
	cin>>h>>w;
	int starnumber=0;
	for(int i=1; i<=h; i++)
	{
		string temp;
		cin>>temp;
		for(int j=1; j<=w; j++)
		{
			if(temp[j-1]=='*')
			{
				starnumber++;
			}
			field[i][j]=temp[j-1];
		}
	}
	bool isplus=false;
	if(w+h<starnumber)
	{
		isplus=false;
		cout<<"NO"<<endl;
	}
	else
	{
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(field[i][j]=='*')
			{
				int left=0;
				int right=0;
				int up=0;
				int down=0;
				//up direction
				int temp=i-1;
				while(field[temp][j]=='*')
				{
					up++;
					temp--;
				}
				//down direction
				temp=i+1;
				while(field[temp][j]=='*')
				{
					down++;
					temp++;
				}
				//right direction
				temp=j+1;
				while(field[i][temp]=='*')
				{
					right++;
					temp++;
				}
				//left direction
				temp=j-1;
				while(field[i][temp]=='*')
				{
					left++;
					temp--;
				}
				bool ispossible=(left>0) && (right >0) && (up>0) &&(down>0);
				int total=left+right+up+down;
				if(ispossible && total+1==starnumber)
				{
					isplus=true;
					break;
				}
			}
		}
		if(isplus)
		{
			cout<<"YES"<<endl;
			break;
		}
	}
	if(!isplus)
	{
		cout<<"NO"<<endl;
	}
	}
	
	
}
