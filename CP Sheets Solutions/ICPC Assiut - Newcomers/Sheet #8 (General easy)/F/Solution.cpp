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
		int r, c;
		cin >> r >> c;
		bool turn = false;
		for (int i = 0; i < r; i++)
		{
			if ((i + 1) % 2)
				cout << string(c, '#') << endl;
			else
			{
				if (turn = !turn)
					cout << string(c - 1, '.') << '#' << endl;
				else
					cout << '#' << string(c - 1, '.') << endl;
			}
		}
	}
	return 0;
}
