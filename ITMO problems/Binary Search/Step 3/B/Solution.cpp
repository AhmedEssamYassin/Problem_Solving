#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isOk(const vector<ll> &vc, int K, ll S)
{
	int countSegments{1};
	ll currentSum{};
	bool singleBad = false;
	for (int i{}; i < vc.size(); i++)
	{
		if (vc[i] > S)
			singleBad |= 1;
		if (currentSum + vc[i] <= S)
			currentSum += vc[i];
		else
			currentSum = vc[i], countSegments++;
	}
	return (countSegments <= K && not singleBad);
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
		ll L{}, R{1LL << 55}, ans;
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (isOk(vc, K, mid))
				ans = mid, R = mid - 1;
			else
				L = mid + 1;
		}
		cout << ans;
	}
	return 0;
}