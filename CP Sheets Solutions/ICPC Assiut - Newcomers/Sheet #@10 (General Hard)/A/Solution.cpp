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
		string str;
		cin >> str;
		int L{}, R = str.length() - 1;
		while (L <= R)
		{
			if (str[L] != '?' and str[R] != '?' and str[L] != str[R]) // They CANNOT be equal
				return cout << -1, 0;

			if (str[L] != '?' and str[R] == '?')
				str[R] = str[L];
			else if (str[L] == '?' and str[R] != '?')
				str[L] = str[R];
			else if (str[L] == '?' and str[R] == '?')
				str[L] = str[R] = 'a';
			L++;
			R--;
		}
		cout << str;
	}
	return 0;
}
