#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPrime(ll N)
{
	if (N < 2)
		return false;
	if (N < 4)
		return true;

	if (N % 2 == 0 || N % 3 == 0)
		return false;
	for (ll i = 5; i * i <= N; i += 6)
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		ll firstPrime = N + 1;
		while (!isPrime(firstPrime))
			firstPrime++;

		if (firstPrime == M)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
