#include <iostream>
#include <string>
using namespace std;
int main()
{
	string cro;
	cin>>cro;
	int ssize=cro.length();
	int num=0;
	cro+="\0";
	for(int i=0; i<ssize; i++)
	{
		if(cro[i]=='c')
		{
			if(cro[i+1])
			{
				if(cro[i+1]=='=' || cro[i+1]=='-')
				{
					i++;
					num++;
				}
				else
				{
					num++;
				}
			}
			else
			{
				num++;
			}
		}
		else if(cro[i]=='d')
		{
			if(cro[i+1])
			{
				if(cro[i+1]=='z')
				{
					if(cro[i+2])
					{
						if(cro[i+2]=='=')
						{
							num++;
							i=i+2;
						}
						else
						{
							num=num+2;;
							i++;
					    }  
					}
					else
					{
						num=num+2;
						i++;
					}
				}
				else if(cro[i+1]=='-')
				{
					i++;
					num++;
				}
				else
				{
					num++;
				}
			}
			else
			{
				num++;
			}
		}
		else if(cro[i]=='l' || cro[i]=='n')
		{
			if(cro[i+1])
			{
				if(cro[i+1]=='j')
				{
					i++;
					num++;
				}
				else
				{
					num++;
				}
			}
			else
			{
				num++;
			}
		}
		else if(cro[i]=='s' || cro[i]=='z')
		{
			if(cro[i+1])
			{
				if(cro[i+1]=='=')
				{
					i++;
					num++;
				}
				else
				{
					num++;
				}
			}
			else
			{
				num++;
			}
		}
		else
		{
			num++;
		}
	}
	cout<<num;
}
