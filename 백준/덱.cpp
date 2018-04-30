#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int com;
	cin >> com;
	deque<int> d;
	string *command = new string[com];
	for (int i = 0; i < com; i++)
	{
		cin >> command[i];
		if (command[i][0] == 'p' && command[i][5] == 'f')//push_front
		{
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (command[i][0] == 'p' && command[i][5] == 'b')//push_back
		{
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (command[i][0] == 'p' && command[i][4] == 'f')//pop_front
		{
			int x;
			if (d.size() != 0)
			{
				x = d.front();
				d.pop_front();
				cout << x << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if (command[i][0] == 'p' && command[i][4] == 'b')//pop_back
		{
			int x;
			if (d.size() != 0)
			{
				x = d.back();
				d.pop_back();
				cout << x << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if (command[i][0] == 's')//size
		{
			int x = d.size();
			cout << x << endl;
		}
		else if (command[i][0] == 'e')//empty
		{
			int x = d.empty();
			cout << x << endl;
		}
		else if (command[i][0] == 'f')//front
		{
			int x;
			if (d.size() != 0)
			{
				x = d.front();
				cout << x << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else//back
		{
			int x;
			if (d.size() != 0)
			{
				x = d.back();
				cout << x << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
	}
}