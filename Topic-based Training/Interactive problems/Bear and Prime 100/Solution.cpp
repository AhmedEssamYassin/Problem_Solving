#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// #define endl "\n"

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
		auto Ask = [&](ll k)
		{
			cout << k << endl;
			string query;
			cin >> query;
			return query;
		};
		ll cnt{};
		for (const ll &d : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53})
		{
			string query = Ask(d);
			cnt += (query == "yes");
			if (d < 11)
			{
				query = Ask(d * d);
				cnt += (query == "yes");
			}
		}
		if (cnt > 1)
			cout << "composite" << endl;
		else
			cout << "prime" << endl;
	}
	return 0;
}