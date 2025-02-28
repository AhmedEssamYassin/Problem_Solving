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
		int x, cur{}, No_of_untreated_crimes{};
		cin >> N;
		while (N--)
		{
			cin >> x;
			if (x > 0)
				cur += x;
			else
			{
				if (cur - 1 < 0)
					No_of_untreated_crimes++;
				else
					cur--;
			}
		}
		cout << No_of_untreated_crimes;
	}
	return 0;
}
