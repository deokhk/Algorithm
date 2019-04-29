#include <iostream>
#include <algorithm>
using namespace std;int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    int sema=max(max(A,B),C);
    int semi=min(min(A,B),C);
    cout<<A+B+C-sema-semi<<endl;
}
