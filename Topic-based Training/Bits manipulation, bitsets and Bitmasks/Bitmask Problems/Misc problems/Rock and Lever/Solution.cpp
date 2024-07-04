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
	Number of pairs such that: (a[i] & a[j]) >= (a[i] ^ a[j])
	(0 & 0) = 0		(0 ^ 0) = 0
	(0 & 1) = 0		(0 ^ 1) = 1
	(1 & 0) = 0		(1 ^ 0) = 1
	(1 & 1) = 1		(1 ^ 1) = 0 (The only valid case for such a bit)
	Since the comparison of the MSB determines which number is bigger
	So we count the number of elements having the same MSB set and choose all combinations of 2 of them
	i.e., freq[i] Choose 2
	*/
	int t = 1;
	ll N, k;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N);
		ll freq[32] = {0};
		for (int i{}; i < N; i++)
			cin >> a[i];

		for (int i{}; i < N; i++)
		{
			ll MSB = 63 - __builtin_clzll(a[i]);
			freq[MSB]++;
		}
		ll cnt{};
		for (int i{}; i < 32; i++)
			cnt += (freq[i] * (freq[i] - 1) / 2); // NC2 = (N) * (N - 1) / 2
		cout << cnt << endl;
	}
	return 0;
}