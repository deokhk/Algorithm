#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string con[1001];
	getline(cin, s);
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		con[i] = s.substr(i, size - i);
	}
	int k = size - 1;
	while(k)
	{
		for (int j = 0; j < k; j++)
		{
			if (con[j].compare(con[j + 1]) > 0)
			{
				string temp = con[j + 1];
				con[j + 1] = con[j];
				con[j] = temp;
			}
		}
		k--;
	}
	for (int i = 0; i < size; i++)
	{
		cout << con[i] << endl;
	}
}