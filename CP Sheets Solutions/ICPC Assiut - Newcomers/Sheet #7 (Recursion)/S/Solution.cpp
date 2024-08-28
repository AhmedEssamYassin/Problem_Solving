#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

long double avg(const vector<ll> &arr, int len)
{
	if (len == 1)
		return arr[0];
	long double subResult = avg(arr, len - 1);
	subResult *= (len - 1);
	return (arr[len - 1] + subResult) / (len);
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
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		cout << fixed << setprecision(7) << avg(vc, N);
	}
	return 0;
}