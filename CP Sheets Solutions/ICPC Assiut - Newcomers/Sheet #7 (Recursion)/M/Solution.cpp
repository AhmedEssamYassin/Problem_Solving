#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll suffixSum(const vector<ll> &arr, int idx, int M)
{
	if (M == 0)
		return 0;
	return (arr[idx - 1] + suffixSum(arr, idx - 1, M - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	int N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		cout << suffixSum(vc, N, M);
	}
	return 0;
}