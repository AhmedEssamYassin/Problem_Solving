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
	ll N;
	// cin >> t;
	while (t--)
	{
		int n, m;
		ll sumA{}, sumB{};
		cin >> n >> m;
		vector<ll> A(n), B(m);
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
			sumA += A[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> B[i];
			sumB += B[i];
		}
		if (sumA == sumB)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}
