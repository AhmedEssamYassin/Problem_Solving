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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		vector<pair<int, int>> vc;
		int s, x, y;
		cin >> s >> N;
		while (N--)
		{
			cin >> x >> y;
			vc.push_back({x, y});
		}
		sort(vc.begin(), vc.end()); // In ascending order, Based on first element
		for (int i = 0; i < vc.size(); i++)
		{
			if (s > vc[i].first)
				s += vc[i].second;
			else
				return cout << "NO", 0;
		}
		cout << "YES";
	}
	return 0;
}
