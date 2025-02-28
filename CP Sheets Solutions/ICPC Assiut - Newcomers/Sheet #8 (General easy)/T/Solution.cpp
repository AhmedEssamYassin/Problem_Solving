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
		vector<char> vc;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '+')
				vc.push_back(str[i]);
		}
		sort(vc.begin(), vc.end());
		for (int i = 0; i < vc.size(); i++)
		{
			cout << vc[i];
			if (i != vc.size() - 1)
				cout << "+";
		}
	}
	return 0;
}
