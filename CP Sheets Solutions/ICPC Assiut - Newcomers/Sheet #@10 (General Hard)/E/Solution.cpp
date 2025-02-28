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
	cin >> t;
	while (t--)
	{
		ll s;
		cin >> N >> s;
		if (s > N * (N + 1) / 2)
			cout << -1 << endl;
		else
		{
			if (s <= N)
				cout << 1 << " " << s << endl;
			else
			{
				vector<ll> ans;
				while (s > N)
					ans.push_back(N), s -= N, N--;
				ans.push_back(s);
				cout << ans.size() << " ";
				for (int i{}; i < ans.size(); i++)
				{
					cout << ans[i];
					if (i != ans.size() - 1)
						cout << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
