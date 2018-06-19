#include <iostream>
using namespace std;
int table[200100];
int main()
{
	int n;
	cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
		{
			if (table[temp+100010] == 0)
			{
				table[temp+100010]++;
				num++;
			}
		}
		else if(temp<0)
		{
			temp = -temp;
			if (table[temp] == 0 )
			{
				table[temp]++;
				num++;
			}
		}
	}
	cout << num << endl;

}