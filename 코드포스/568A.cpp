#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> pos(3);
	int d;
	for(int i=0; i<3; i++)
	{
		cin>>pos[i];
	}
	cin>>d;
	sort(pos.begin(),pos.end());
	int t1=(pos[1]-pos[0]>d) ? 0 : d-(pos[1]-pos[0]);
	int t2=(pos[2]-pos[1]>d) ? 0 : d-(pos[2]-pos[1]);
	
	cout<<t1+t2<<endl;
}
