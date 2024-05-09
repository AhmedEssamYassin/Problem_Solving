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
	int h, w;
	int t = 1;
	cin >> t;
	while (t--)
	{
		cin >> h >> w;
		if (h == w)
			cout << "Square" << endl;
		else
			cout << "Rectangle" << endl;
	}
	return 0;
}