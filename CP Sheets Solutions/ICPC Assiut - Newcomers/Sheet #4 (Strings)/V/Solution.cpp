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
		string str;
		cin >> str;

		int pos, prevPos{};
		while ((pos = str.find("EGYPT", prevPos)) != -1) // ITALYKOREAEGYPTEGYPTALGERIAEGYPTZ
			str.replace(pos, 5, " "), prevPos = pos;
		cout << str;
	}
	return 0;
}