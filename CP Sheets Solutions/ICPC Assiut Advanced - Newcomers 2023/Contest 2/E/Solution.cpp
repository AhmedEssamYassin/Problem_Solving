#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool Is_Prime(ll N)
{
	if (N < 2)
		return false;
	if (N <= 3)
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
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	/*
	The problem is to find the sum of ALL prime numbers in range [L, R] and the final price which will be paid for the last chicken wing
	(Price starts with 0 and Each time, Price increases by 1)
	*/
	ll L, R;
	cin >> L >> R;
	ll Sum{}, Price = 0;
	for (ll i{L}; i <= R; i++)
	{
		if (Is_Prime(i))
		{
			Sum += i;
			Price++;
		}
	}
	cout << Sum << " " << Price;

	return 0;
}