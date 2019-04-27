#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int A,B;
	cin>>A>>B;
	vector<int> res;
	res.push_back(A+B);
	res.push_back(2*A-1);
	res.push_back(2*B-1);
	sort(res.begin(),res.end());
	cout<<res[2]<<endl;
}
