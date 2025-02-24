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
	int t = 1;
	ll N, K;
	// cin >> t;
	while (t--)
	{
		cin >> N >> K;
		vector<ll> vc(N);
		set<int> st;
		int freq[100009] = {0};
		for (int i{}; i < N; i++)
			cin >> vc[i];

		ll L{}, R{}, maxCount{};
		while (R < N)
		{
			st.insert(vc[R]);
			freq[vc[R]]++;
			while (st.size() > K && L <= R)
			{
				freq[vc[L]]--;
				if (freq[vc[L]] == 0)
					st.erase(vc[L]);
				L++;
			}
			maxCount += (R - L + 1);
			R++;
		}
		cout << maxCount;
	}
	return 0;
}