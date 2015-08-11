#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
	int d = 0;
	vector<long long> M;

	if(A.size() == 0)
	{
		return 0;
	}

	for(unsigned int i = 0; i < A.size(); ++i)
	{
		M.push_back((long long)i-A[i]);
	}

	sort(M.begin(),M.end());

	for(unsigned int i = 0; i < A.size()-1; ++i)
	{
		unsigned int j=i+1;

		while(M[j] <= i+A[i] && j++ < M.size())
		{
			if(++d > 10000000)
			{
				return -1;
			}
		}
	}
	return d;
}

int main()
{
	int v[] = { 1, 5, 2, 1, 4, 0 };
	vector<int> A(v, v + sizeof(v) / sizeof(v[0]));

	cout << solution(A) << endl;

	return 0;
}
