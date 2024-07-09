#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> shiftZeros(const vector<ll> &vc)
{
	vector<ll> res;
	int cntZero{};
	for (int i = 0; i < vc.size(); i++)
		cntZero += (!vc[i]);
	for (int i{}; i < vc.size(); i++)
	{
		if (vc[i] != 0)
			res.push_back(vc[i]);
	}
	while (cntZero--)
		res.push_back(0);
	return res;
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
		vector<ll> ans = shiftZeros(a);
		for (int i{}; i < ans.size(); i++)
			cout << ans[i] << " ";
	}
	return 0;
}