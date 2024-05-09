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
#endif // !ONLINE_JUDGE
	int t = 1, N;
	// cin >> t;
	while (t--)
	{
		// 0 1 1 2 3 5 8 13 21 34 55
		cin >> N;
		long long arr[51];
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < 51; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[N - 1];
	}

	return 0;
}