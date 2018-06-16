#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	queue<int> q1;
	queue<int> q2;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		q2.push(i);
	}
	while (v.size()!=n)
	{
		for (int count = 0; count < m-1; count++)
		{
			if (q2.size() == 0 && q1.size()!=0)
			{
				int size = q1.size();
				for (int i = 0; i < size; i++)
				{
					q2.push(q1.front());
					q1.pop();
				}
			}
			q1.push((q2.front()));
			q2.pop();
		}
		if (q2.size() == 0 && q1.size() != 0)
		{
			int size = q1.size();
			for (int i = 0; i < size; i++)
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
		v.push_back(q2.front());
		q2.pop();
	}
	cout << '<';
	for (int i = 0; i < v.size(); i++)
	{
		if (i != n - 1)
		{
			cout <<v[i]<< ", ";
		}
		else
		{
			cout << v[i];
		}
	}
	cout << '>';

}