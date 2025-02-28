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
		/*
		The answer to the query Li, Ri is the number of such integers i (Li <= i < Ri), that Str[i] = Str[i + 1]
		Pay attention to the interval [L, R), it's half open (R is NOT included)
		*/
		string str;
		cin >> str;
		N = str.length();
		int *pref{new int[N]{0}};

		for (int i{}; i < N - 1; i++)
			pref[i] += (i > 0 ? pref[i - 1] : 0) + (str[i] == str[i + 1]); // Adds 1 to the prefix sum iff Str[i] = Str[i + 1]
		ll Q;
		cin >> Q;
		while (Q--)
		{
			ll L, R;
			cin >> L >> R;
			L--, R--; // To be 0-based
			cout << pref[R - 1] - (L > 0 ? pref[L - 1] : 0) << endl;
		}
		delete[] pref;
	}
	return 0;
}
