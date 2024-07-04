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
	∑ ∑ ∑ (a[i] & a[j]) . (a[j] | a[k])
	We can rearrange the sigmas so that the sigma with the variable j comes first

	The term (a[i] & a[j]) is constant w.r.t the sigma with variable k, so we can take it as a common factor
	∑ ∑ [(a[i] & a[j]) ∑ (a[j] | a[k])]

	The term ∑ (a[j] | a[k]) is constant w.r.t the sigma with variable i, so we can take it as a common factor
	∑ [∑ (a[j] | a[k]) * ∑ (a[i] & a[j])]

	Now, we need to calculate ∑ (a[i] & a[j]) and also ∑ (a[j] | a[k]) fast enough
	Let's fix a[j] = C, and look carefully at the binary representation of C
	- If a bit is set (1) in C:
		- It will be also set (1) when ANDed with every number having this bit set
		- It will always be set (1) when ORed with every number
	- Else if a bit is cleared (0) in C:
		- It CANNOT be set in when ANDed with any number
		- It will be set (1) when ORed with every number having this bit set
	and since we are adding terms ANDed or ORed with C
	we need to maintain the frequency of every bit, in how many numbers it was set
	Then we just add (1LL << i) * (number of terms will have this bit set when ANDed or ORed)
	*/
	int t = 1;
	ll N;
	cin >> t;
	const ll mod = 1e9 + 7;
	ll powerMod[61] = {0};
	powerMod[0] = 1;
	for (int i{1}; i < 61; i++)
		powerMod[i] = (powerMod[i - 1] << 1) % mod;
	while (t--)
	{
		cin >> N;
		vector<ll> X(N);
		for (int i{}; i < N; i++)
			cin >> X[i];

		ll freq[61] = {0};
		for (int i{}; i < N; i++)
		{
			ll cur = X[i], idx{};
			while (cur)
				freq[idx++] += (cur & 1), cur >>= 1;
		}

		ll sum{};
		for (int j{}; j < N; j++)
		{
			ll C = X[j]; // Fixing X[j]
			ll SigmaAND = 0;
			ll SigmaOR = 0;
			for (int i{}; i < 61; i++, C >>= 1)
			{
				if (C & 1)
				{
					SigmaAND = (SigmaAND + freq[i] * powerMod[i] % mod) % mod;
					SigmaOR = (SigmaOR + N * powerMod[i] % mod) % mod;
				}
				else
					SigmaOR = (SigmaOR + freq[i] * powerMod[i] % mod) % mod;
			}
			sum = (sum + SigmaAND % mod * SigmaOR % mod) % mod;
		}
		cout << sum << endl;
	}
	return 0;
}