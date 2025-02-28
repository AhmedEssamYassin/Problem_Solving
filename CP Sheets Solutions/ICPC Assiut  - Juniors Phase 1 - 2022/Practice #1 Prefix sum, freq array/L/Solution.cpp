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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int N = str.length();
		vector<vector<int>> charFreq(N + 1, vector<int>(96, 0));
		// To store the frequency of each of the 3 characters {'/', '\\', '_'} at each position

		for (int i{}; i < N; i++)
		{
			charFreq[i + 1] = charFreq[i]; // Copy the frequency of ALL characters
			charFreq[i + 1][str[i]]++;
		}
		cin >> Q;
		while (Q--)
		{
			ll L, R;
			cin >> L >> R;
			L--, R--; // To be 0-based

			int forwardSlash = charFreq[R + 1]['/'] - charFreq[L]['/'];
			int backwardSlash = charFreq[R + 1]['\\'] - charFreq[L]['\\'];
			int underScore = charFreq[R + 1]['_'] - charFreq[L]['_'];

			// 1 2 3 4 5 ... Xth level of each of '/' and '\\'
			// X² + X - 2 * min(forwardSlash, backwardSlash) = 0
			int mn = min(forwardSlash, backwardSlash);
			int height = (-1 + sqrtl(1 + 8 * mn)) / 2;

			// 1 2 3 4 5 ... Xth level
			// X² + X - 2 * underScore = 0
			int base = (sqrtl(1 + 8 * underScore) + 1) / 2;
			cout << min(height, base) << endl;
		}
	}
	return 0;
}
