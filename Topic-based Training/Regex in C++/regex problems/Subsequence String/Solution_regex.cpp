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
	int N;
	// cin >> t;
	while (t--)
	{
		string str;
		regex RGX_hello("[a-z]+[h][a-z]+[e][a-z]+[l][a-z]+[l][a-z]+[o][a-z]+");
		cin >> str;
		if (regex_match(str, RGX_hello))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}