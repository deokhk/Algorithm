#include <iostream>
using namespace std;
int N;
int node[26][2];
void pre(int x);
void in(int x);
void post(int x);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char temp,temp1,temp2;
		cin >> temp>>temp1>>temp2;
		int tep = temp - 'A';
		int tep1 = temp1 - 'A';
		int tep2 = temp2 - 'A';
		node[tep][0] = tep1;
		node[tep][1] = tep2;
	}
	pre(0);
	cout << '\n';
	in(0);
	cout << '\n';
	post(0);
	cout << '\n';
}
void pre(int x)
{
	if (x != '.' - 'A')
	{
		cout << char(x + 'A');
		pre(node[x][0]);
		pre(node[x][1]);
	}

}
void in(int x)
{
	if (x != '.' - 'A')
	{
		in(node[x][0]);
		cout << char(x + 'A');
		in(node[x][1]);
	}
}
void post(int x)
{
	if (x != '.' - 'A')
	{
		post(node[x][0]);
		post(node[x][1]);
		cout << char(x + 'A');
	}
}