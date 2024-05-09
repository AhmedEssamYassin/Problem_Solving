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
#endif // !ONLINE_JUDGE
	int t = 1, N, Q, L, R;
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		int *arr = new int[N];
		ll *Prefix_sum = new ll[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		Prefix_sum[0] = arr[0];
		for (int i{1}; i < N; i++)
			Prefix_sum[i] = Prefix_sum[i - 1] + arr[i];

		while (Q--)
		{
			cin >> L >> R;
			L--, R--; // To make L and R 0-based

			L > R ? swap(L, R) : void(NULL); // To make L <= R

			cout << Prefix_sum[R] - (L > 0 ? Prefix_sum[L - 1] : 0) << endl;
		}

		delete[] Prefix_sum;
		delete[] arr;
	}

	return 0;
}