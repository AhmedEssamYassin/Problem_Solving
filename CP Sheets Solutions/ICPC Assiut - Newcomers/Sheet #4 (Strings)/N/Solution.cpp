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
	int N;
	// cin >> t;
	while (t--)
	{
		int len = 1; // Minimum possible string length is 1 (which will be a single character)
		string S;
		cin >> N >> S;

		// Subsequence means to leave or delete some number (possible 0) of characters but maintain the order!
		for (int i = 1; i < N; i++)
		{
			if (S[i] == S[i - 1])
				continue; // Delete of the longest subsequence
			else
				len++; // Add to the longest subsequence
		}
		cout << len;
	}
	return 0;
}