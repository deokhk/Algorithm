#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<int> mt(N);
	for(int i=0; i<N; i++)
	{
		cin>>mt[i];
	}
	int answer=1;
	for(int i=1; i<N; i++)
	{
		bool ispossible=true;
		for(int j=i-1; j>=0; j--)
		{
			if(mt[i]<mt[j])
			{
				ispossible=false;
				break;
			}
		}
		if(ispossible)
		{
			answer++;
		}
	}
	cout<<answer<<endl;
}
