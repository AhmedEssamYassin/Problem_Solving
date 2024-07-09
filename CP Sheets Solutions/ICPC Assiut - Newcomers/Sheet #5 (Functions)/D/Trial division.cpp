#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPrime(const ll &N)
{
	if (N < 2)
		return false;
	if (N < 4)
		return true;
	if (N % 2 == 0 || N % 3 == 0)
		return false;
	for (ll i{5}; i * i <= N; i += 6)
	{
		if (N % i == 0 || N % (i + 2) == 0)
			return false;
	}
	return true;
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
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (isPrime(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}