#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<float> score(N);
	float mscore=-1.0;
	for(int i=0; i<N; i++)
	{
		cin>>score[i];
		mscore=max(mscore,score[i]);
	}
	float newav=0;
	for(int i=0; i<N; i++)
	{
		score[i]=(score[i]/(float)mscore)*100;
		newav+=score[i];
	}
	cout<<newav/N<<endl;
	
	
}
