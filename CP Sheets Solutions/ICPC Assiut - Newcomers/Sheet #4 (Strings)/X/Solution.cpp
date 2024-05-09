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
		string str, t, r, m;
		cin >> str;
		m = str;
		for (int i = 0; i < str.size() - 1; i++)
		{
			t = str.substr(0, i + 1);
			r = str.substr(i + 1, str.size() - i - 1);
			sort(t.begin(), t.end());
			sort(r.begin(), r.end());
			m = min(m, t + r);
		}
		cout << m;
	}
	return 0;
}