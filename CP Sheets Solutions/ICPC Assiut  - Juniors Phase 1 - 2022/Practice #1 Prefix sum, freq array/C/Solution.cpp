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
		string Input, Text;
		getline(cin, Input);
		getline(cin, Text);

		ll freq[123]{}; // Frequency array for lowercase and uppercase characters
		for (const char &C : Input)
			freq[C]++;

		for (const char &C : Text)
		{
			if (freq[C] == 0) // If the character is NOT existing, he CANNOT compose the needed text
				return cout << "NO", 0;

			if (C != ' ') // He does NOT cut spaces out of the heading.
				freq[C]--;
		}
		cout << "YES";
	}
	return 0;
}
