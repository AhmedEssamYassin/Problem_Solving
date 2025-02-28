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
		string S, T;
		cin >> S >> T;
		int RS = S.length() - 1; // 0-indexed
		int RT = T.length() - 1; // 0-indexed
		while (RT >= 0 and RS >= 0)
		{
			if (S[RS] != T[RT])
				break;
			RS--, RT--;
		}
		cout << (RS + 1) + (RT + 1); // 1-indexed
	}
	return 0;
}
