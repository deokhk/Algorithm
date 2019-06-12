#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<char> state;
	for(int ts=0; ts<3; ts++)
	{
		int flip=0;
		for(int i=0; i<4; i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp==0)
			{
				flip++;
			}
		}
		if(flip>0)
		{
			char x='A'+(flip-1);
			state.push_back(x);
		}
		else
		{
			state.push_back('E');
		}
	}
	for(int i=0; i<3; i++)
	{
		cout<<state[i]<<endl;
	}
}
