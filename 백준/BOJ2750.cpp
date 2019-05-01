#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        cout<<arr[i]<<endl;
    }
}
