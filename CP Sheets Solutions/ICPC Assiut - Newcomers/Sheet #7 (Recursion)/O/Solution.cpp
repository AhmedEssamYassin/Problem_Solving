#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll fibonacci(ll N)
{
	if (N == 1)
		return 0;
	if (N == 2)
		return 1;
	return fibonacci(N - 1) + fibonacci(N - 2);
}

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
		cin >> N;
		cout << fibonacci(N);
	}
	return 0;
}