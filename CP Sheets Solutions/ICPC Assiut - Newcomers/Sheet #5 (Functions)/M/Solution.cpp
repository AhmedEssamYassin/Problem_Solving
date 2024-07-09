#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll countDistinct(const vector<ll> &vc)
{
	set<ll> st;
	for (int i = 0; i < vc.size(); i++)
		st.insert(vc[i]);
	return st.size();
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		cout << countDistinct(a);
	}
	return 0;
}