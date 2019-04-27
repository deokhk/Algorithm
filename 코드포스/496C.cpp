#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	vector<int> findpair;
	vector<int> twogroup[31];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
	}
	sort(seq.begin(), seq.end());
	int seqsize = seq.size();
	if (seqsize >= 2)
	{
		for (int i = 0; i < seqsize; i++)
		{
			int temptwo = log2(seq[i]);
			int powtwo = pow(2, temptwo+1);
			int numtofind = powtwo - seq[i];
			int numtemptwo = log2(numtofind);
			int numsize = twogroup[numtemptwo].size();
			for (int j = 0; j < numsize; j++)
			{
				if (twogroup[numtemptwo][j] == numtofind)
				{
					findpair.push_back(seq[i]);
					findpair.push_back(numtofind);
					break;
				}
			}
			twogroup[temptwo].push_back(seq[i]);
		}
		int answer = 0;
		sort(findpair.begin(), findpair.end());
		int fsize = findpair.size();
		int length = 1;
		if (fsize)
		{
			for (int i = 1; i < fsize; i++)
			{
				if (findpair[i - 1] == findpair[i])
				{
					continue;
				}
				findpair[length++] = findpair[i];
			}
		}
		int j = 0;
		for (int i = 0; i < n && j<length && findpair.size()>=1; i++)
		{
			if (findpair[j] == seq[i])
			{
				answer++;
			}
			else
			{
				j++;
				if (findpair[j] == seq[i])
				{
					answer++;
				}
			}
		}
		printf("%d\n", seqsize-answer);
	}
	else
	{
		printf("1\n");
	}

}