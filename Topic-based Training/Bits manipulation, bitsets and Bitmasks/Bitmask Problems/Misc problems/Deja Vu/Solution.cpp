#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t, N, Q, Xi;
	cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		ll *arr = new ll[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		/*
		For some N to be divisible by 2^x, It must have trailing zeros >= x
		Notice that if we make an operation on x = 4 for example, we CANNOT make any operations on any x >= 4 any more
		because the operation on x have left all numbers with number of trailing zeros = (x - 1)
		that means any further larger or equal x will NOT be considered
		*/
		int min_op{31};
		while (Q--)
		{
			cin >> Xi;
			if (Xi < min_op)
			{
				min_op = Xi;
				for (int j{}; j < N; j++)
				{
					if (__builtin_ctz(arr[j]) >= Xi)
						arr[j] += (1LL << (Xi - 1));
				}
			}
		}
		for (int i{}; i < N; i++)
			cout << arr[i] << " \n"[i == N - 1];

		delete[] arr;
	}
	return 0;
}