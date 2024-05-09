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
#endif // !ONLINE_JUDGE

	regex Rgx("[Mm]+[Ee]+[Oo]+[Ww]+");
	int t, len;
	string Sound;
	cin >> t;
	while (t--)
	{
		cin >> len >> Sound;
		if (regex_match(Sound, Rgx))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}