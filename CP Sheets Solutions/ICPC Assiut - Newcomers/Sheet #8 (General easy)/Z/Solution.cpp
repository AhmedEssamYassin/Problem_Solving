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
		string S;
		cin >> N >> S;
		deque<char> ans;
		if (N & 1) // Odd number of characters
		{
			while (S.size()) // Until the string vanishes
			{
				ans.push_back(S[0]);
				if (S.size() > 1)
					ans.push_front(S[1]);
				S.erase(0, 2);
			}
			for (const auto &c : ans)
				cout << c;
		}
		else // Even number of characters
		{
			while (S.size()) // Until the string vanishes
			{
				ans.push_front(S[0]);
				if (S.size() > 1)
					ans.push_back(S[1]);
				S.erase(0, 2);
			}
			for (const auto &c : ans)
				cout << c;
		}
	}
	return 0;
}
