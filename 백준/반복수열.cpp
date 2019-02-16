#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool check[1000000];
vector<int> seq;
int A, P;
void dfs(int x);
int main()
{
	int ans = 0;
	cin >> A >> P;
	dfs(A);
	int vsize = seq.size();
	int keynum = seq[vsize - 1];
	for (int i = 0; i < vsize; i++)
	{
		ans++;
		if (seq[i] == keynum)
		{
			break;
		}
	}
	ans = ans - 1;
	cout << ans << '\n';

}
void dfs(int x)
{
	seq.push_back(x);
	check[x] = true;
	string s = to_string(x);
	int newnum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		newnum += pow(s[i] - '0', P);
	}
	if (check[newnum] == false)
	{
		dfs(newnum);
	}
	else
	{
		seq.push_back(newnum);
	}

}