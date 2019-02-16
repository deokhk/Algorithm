#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> people(N);
	for (int i = 0; i < N; i++)
	{
		cin >> people[i];
	}
	sort(people.begin(), people.end());
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += (N - i)*people[i];
	}
	cout << answer << endl;

}