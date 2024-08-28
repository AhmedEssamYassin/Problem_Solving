#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool createExpr(const vector<ll> &arr, int idx, ll val, ll X)
{
	if (idx == arr.size())
		return (val == X);

	return (createExpr(arr, idx + 1, val + arr[idx], X) || createExpr(arr, idx + 1, val - arr[idx], X));
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
	ll N, X;
	// cin >> t;
	while (t--)
	{
		cin >> N >> X;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		// There CANNOT be a sign before the first element, because he said "between" every two numbers
		if (createExpr(vc, 1, vc[0], X))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}