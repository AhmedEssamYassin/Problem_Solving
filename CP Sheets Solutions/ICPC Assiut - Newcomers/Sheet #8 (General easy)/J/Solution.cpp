#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isLucky(string str)
{
	for (const char &c : str)
		if (c != '4' and c != '7')
			return false;
	return true;
}

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
		cin >> N;
		for (ll i = 1; i * i <= N; i++)
		{
			if (N % i == 0)
			{
				string div1 = to_string(i), div2 = to_string(N / i);
				if (isLucky(div1) || isLucky(div2))
					return cout << "YES", 0;
			}
		}
		cout << "NO";
	}
	return 0;
}
