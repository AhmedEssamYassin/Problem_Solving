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
		int cnt{};
		for (int i = 0; i < str.length(); i++)
		{
			if (i == 0)
				cnt += min(abs('a' - str[i]), 26 - abs('a' - str[i]));
			else
				cnt += min(abs(str[i - 1] - str[i]), 26 - abs(str[i - 1] - str[i]));
		}
		cout << cnt;
	}
	return 0;
}
