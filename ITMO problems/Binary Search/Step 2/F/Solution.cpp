#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isOk(string T, string P, const vector<int> &a, const ll &mid)
{
	// Mark deleted characters (better than literally erasing, to maintain correct order of indices)
	for (int i{}; i < mid; i++)
		T[a[i]] = ' ';

	string subsequence("");
	for (int i{}, j{}; i < P.length(); i++)
	{
		for (; j < T.length(); j++)
		{
			if (T[j] == ' ')
				continue;
			if (P[i] == T[j])
			{
				subsequence += P[i];
				j++;
				break;
			}
		}
	}
	return (subsequence == P);
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
		string T, P;
		cin >> T >> P;
		int len = T.length();
		vector<int> a(len);
		for (int i{}; i < len; i++)
			cin >> a[i], a[i]--;
		int ans{};
		ll L{}, R{len << 1};
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (isOk(T, P, a, mid))
			{
				ans = mid; // A candidate solution
				// Search for a better (larger) answer
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		cout << ans;
	}
	return 0;
}