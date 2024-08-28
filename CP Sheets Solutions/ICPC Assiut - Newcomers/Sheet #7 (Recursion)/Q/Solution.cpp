#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll threeNplus1(ll N)
{
	if (N == 1)
		return 1;
	if (N & 1) // ODD
		return 1 + threeNplus1(3 * N + 1);
	else
		return 1 + threeNplus1(N / 2);
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		cout << threeNplus1(N);
	}
	return 0;
}