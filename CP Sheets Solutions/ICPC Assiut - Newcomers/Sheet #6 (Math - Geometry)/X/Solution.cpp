#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool bySec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
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
		vector<pair<int, int>> V(4);
		for (int i = 0; i < 4; i++)
			cin >> V[i].first >> V[i].second;
		int n, xi, yi;
		cin >> n;
		while (n--)
		{
			cin >> xi >> yi;
			sort(V.begin(), V.end());
			bool check1 = (xi >= V[0].first && xi <= V[3].first);
			sort(V.begin(), V.end(), bySec);
			bool check2 = (yi >= V[0].second && yi <= V[3].second);
			if (check1 && check2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}