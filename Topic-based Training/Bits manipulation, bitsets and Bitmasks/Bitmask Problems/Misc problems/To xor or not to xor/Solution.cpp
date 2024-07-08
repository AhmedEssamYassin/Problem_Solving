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
	/*

	*/
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> A(N);
		for (int i{}; i < N; i++)
			cin >> A[i];

		ll ans = 0;
		while (1) // O(N)
		{
			ll t = *max_element(A.begin(), A.end()); // O(N)
			if (t == 0)
				break;
			for (int i{}; i < N; i++) // O(N)
				A[i] = min(A[i], (A[i] ^ t));
			ans = max(ans, (ans ^ t));
		}
		cout << ans;
	}
	return 0;
}