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
		ll x, d, cur{}, No_of_distressed_children{};
		cin >> N >> x;
		cur += x;
		char c;
		while (N--)
		{
			cin >> c >> d;
			if (c == '+')
				cur += d;
			else
			{
				if (cur - d < 0)
					No_of_distressed_children++;
				else
					cur -= d;
			}
		}
		cout << cur << " " << No_of_distressed_children;
	}
	return 0;
}
