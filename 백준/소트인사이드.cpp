#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<int> digit;
	while(N>0)
	{
		int tmp=N%10;
		digit.push_back(tmp);
		N/=10;
	}
	sort(digit.begin(),digit.end());
	for(int i=digit.size()-1; i>=0; i--)
	{
		cout<<digit[i];
	}
}
