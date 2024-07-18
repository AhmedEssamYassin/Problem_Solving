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
		cin >> N;
		vector<ll> arr[N];
		arr[0].push_back(1);

		for (int i = 1; i < N; i++)
		{
			arr[i].push_back(1);
			for (int j = 2; j <= i; j++)
				arr[i].push_back(arr[i - 1][j - 2] + arr[i - 1][j - 1]);
			arr[i].push_back(1);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < arr[i].size(); j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}