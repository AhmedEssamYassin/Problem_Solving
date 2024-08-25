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
	If we have a number C[i] which has its set bits occurring in ALL other numbers (ORed together)
	Let that number be X
	Then we can always put that number in a separate set be S1, and ALL other numbers in the other set, be S2
	Now, if any of the numbers in S2 has a set bit NOT occurring in X, we can simply add it to S1
	In the worst case, all numbers in S2 would have set bits not occurring in X, put them all in S1
	and still, we have two different sets! because S2 doesn't contain X unlike S1.
	And now we guarantee that f(S1) = f(S2).
	*/
	int t = 1;
	ll N, K;
	cin >> t;
	while (t--)
	{
		cin >> N;
		map<ll, ll> freq;
		vector<vector<ll>> C(N);
		for (int i = 0; i < N; i++)
		{
			ll k;
			cin >> k;
			while (k--)
			{
				ll p;
				cin >> p;
				C[i].push_back(p);
				freq[p]++;
			}
		}
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			bool ok = true;
			for (const ll &p : C[i])
				ok &= (freq[p] - 1 > 0);
			if (ok)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}