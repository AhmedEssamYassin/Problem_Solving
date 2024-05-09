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
		// You can NOT remove or reorder the characters while making the new strings.
		int L, R, cnt{};
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'L')
				L++;
			if (str[i] == 'R')
				R++;
			if (L == R)
			{
				cnt++;
				L = R = 0;
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'L')
			{
				cout << str[i];
				L++;
			}
			if (str[i] == 'R')
			{
				cout << str[i];
				R++;
			}
			if (L == R)
			{
				cout << endl;
				L = R = 0;
			}
		}
	}
	return 0;
}