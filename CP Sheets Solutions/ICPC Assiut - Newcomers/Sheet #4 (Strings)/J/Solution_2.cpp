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
		string S;
		cin >> S;
		sort(S.begin(), S.end()); // To make characters appear in their alphabetical order

		int cnt = 1; // Every character in the string S at least appears once
		for (int i{1}; i < S.length(); i++)
		{
			if (S[i] == S[i - 1])
				cnt++;
			else
			{
				cout << S[i - 1] << " : " << cnt << endl;
				cnt = 1; // Resets cnt to 1 in order to count occurrences of the next character
			}
			// The last character doesn't precede any other characters
			// so the condition will never be false, thus its frequency won't ever be printed
			if (i == S.size() - 1)
				cout << S[i] << " : " << cnt << endl;
		}
	}
	return 0;
}