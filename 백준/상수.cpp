#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	int A,B;
	cin>>A>>B;
	A=100*(A%10)+10*(A/10-(A/100)*10)+(A/100);
	B=100*(B%10)+10*(B/10-(B/100)*10)+(B/100);
	cout<<max(A,B)<<endl;
}
