#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isOk(const vector<ll> &vc, int K, ll dist)
{
	int positionedCows{1}; // Put a cow into the first stall
	int current = vc[0];
	for (int i{1}; i < vc.size(); i++)
	{
		if (vc[i] - current >= dist)
		{
			positionedCows++;
			if (positionedCows == K)
				return true;
			current = vc[i];
		}
	}
	return false;
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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		cin >> N >> K;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		ll L{}, R{1LL << 40}, ans{-1};
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (isOk(vc, K, mid))
			{
				ans = mid;	 // Candidate solution
				L = mid + 1; // Search for a better (larger) answer
			}
			else
				R = mid - 1;
		}
		cout << ans;
	}
	return 0;
}