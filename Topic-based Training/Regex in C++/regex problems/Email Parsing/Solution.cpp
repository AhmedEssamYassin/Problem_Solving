#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
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
	int N, K;
	string email;
	// cin >> t;
	while (t--)
	{
		regex Rgx_mail("[a-zA-Z0-9_]+[@][a-zA-Z0-9_]+[.][a-zA-Z0-9_]+");
		cin >> email;
		if (regex_match(email, Rgx_mail))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}