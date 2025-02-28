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
	ll N;
	ll Fib[51], ans[51];
	Fib[0] = 0, Fib[1] = 1;
	for (int i = 2; i < 51; i++)
		Fib[i] = Fib[i - 1] + Fib[i - 2];

	for (int i = 0; i < 51; i++)
		ans[i] = isPrime(Fib[i]);
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (ans[N - 1])
			cout << "prime" << endl;
		else
			cout << "not prime" << endl;
	}
	return 0;
}
