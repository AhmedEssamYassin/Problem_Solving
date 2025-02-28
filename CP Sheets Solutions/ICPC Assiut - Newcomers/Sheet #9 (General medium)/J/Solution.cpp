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
		int m, x, y;
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		cin >> m;
		while (m--)
		{
			cin >> x >> y;
			x--; // to make it 0-indexed
			if (x - 1 >= 0)
				arr[x - 1] += (y - 1);
			if (x + 1 < N)
				arr[x + 1] += (arr[x] - y);
			arr[x] = 0;
		}
		for (int i{}; i < N; i++)
			cout << arr[i] << endl;
		delete arr;
	}
	return 0;
}
