#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

long double avg(const vector<long double> &vc)
{
	long double res{};
	for (int i{}; i < vc.size(); i++)
		res += vc[i];
	res /= (vc.size());
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
	ll N, X, Y;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<long double> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		cout << fixed << setprecision(7) << avg(a);
	}
	return 0;
}