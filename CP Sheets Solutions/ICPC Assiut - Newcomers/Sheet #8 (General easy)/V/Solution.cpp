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
		int a, b;
		cin >> N;
		bool is_sorted_descending = true;
		int temp = -1;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			if (a != b)
				return cout << "rated", 0;
			if (a > temp && i > 0)
				is_sorted_descending = false;
			else
				temp = a;
		}
		if (is_sorted_descending == true)
			cout << "maybe";
		else
			cout << "unrated";
	}
	return 0;
}
