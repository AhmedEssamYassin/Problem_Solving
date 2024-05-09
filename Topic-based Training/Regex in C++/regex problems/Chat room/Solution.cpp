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
	int t = 1, N;
	string word;
	regex HELLO_reg("[a-z]{0,}[h][a-z]{0,}[e][a-z]{0,}[l][a-z]{0,}[l][a-z]{0,}[o][a-z]{0,}");
	// cin >> t;
	while (t--)
	{
		cin >> word;
		if (regex_match(word, HELLO_reg))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}