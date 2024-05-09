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

	int N, Q;
	cin >> N >> Q;
	int *arr = new int[N];
	uint64_t *Prefix_sum = new uint64_t[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	Prefix_sum[0] = arr[0];
	for (int i{1}; i < N; i++)
		Prefix_sum[i] = Prefix_sum[i - 1] + arr[i];

	int L, R;
	while (Q--)
	{
		cin >> L >> R; // 1-based

		R--, L--; // To make them 0-based
		cout << Prefix_sum[R] - (L > 0 ? Prefix_sum[L - 1] : 0) << endl;
	}
	delete[] arr;
	delete[] Prefix_sum;

	return 0;
}