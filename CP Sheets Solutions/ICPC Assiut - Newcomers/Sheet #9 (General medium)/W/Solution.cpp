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
		cin >> N;
		string S;
		map<string, int> mp;
		while (N--)
		{
			cin >> S;
			mp[S]++;
		}
		cout << max_element(mp.begin(), mp.end(), [&](const auto &x, const auto &y)
							{ return x.second < y.second; }) // Sorting on basis of number of goals
					->first;								 // Getting the name of the winner
	}
	return 0;
}
