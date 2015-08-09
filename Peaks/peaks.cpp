#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A)
{
	if (A.size() < 3)
	{
		return 0;
	}

	// vector of peak positions
	vector<int> P;

	for (unsigned int i = 1; i < A.size() - 1; ++i)
	{
		if (A[i - 1] < A[i] && A[i] > A[i + 1])
		{
			P.push_back(i);
		}
	}

	if (P.size() == 0)
	{
		return 0;
	}

	for (unsigned int i = 3; A.size() / 2 >= i; ++i)
	{
		bool peaks = true;

		if (A.size() % i == 0)
		{
			int P_i = 0;

			for (unsigned int j = 0; i * j < A.size(); ++j)
			{
				// go to the next peak in the range i*j
				while (P[P_i] < i * j && P_i < P.size())
				{
					P_i++;
				}

				// the block does not contain a peak in the range i*j < P <= i*(j+1)
				// or there are not enough peaks left
				if (P[P_i] >= i * (j + 1) || (P.size() - P_i) < (A.size() / i - j))
				{
					peaks = false;
					break;
				}
				P_i++;
			}
			if (peaks)
			{
				return A.size() / i;
			}
		}
	}
	return 1;
}

int main()
{
	int v[] = { 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };
	vector<int> A(v, v + sizeof(v) / sizeof(v[0]));

	cout << solution(A) << endl;

	return 0;
}
