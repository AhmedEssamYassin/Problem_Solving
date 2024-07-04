#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll modBinExp(ll N, ll power, ll mod)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = (res % mod * N % mod) % mod;
		N = (N % mod * N % mod) % mod;
		power >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	construct an array a[] is of length N
	where 0 <= a[i] <= (1 << k) - 1, i.e., each number is at most k bits
	Bitwise AND of the while array is 0
	Maximum possible sum
	let's assume we have an array of all elements having k set bits
	To make the AND of this whole array = 0, we need to clear each bit in at least one of the elements
	Since we want the maximum sum, it's not useful to clear a bit in more than one element
	000000000000...kth 0
	Each bit must be cleared in one of the N elements
	So, the total number of combinations of turning off a bit in one the elements is (N power k)
	*/
	int t = 1;
	ll N, k;
	cin >> t;
	const int mod = 1e9 + 7;
	while (t--)
	{
		cin >> N >> k;
		cout << modBinExp(N, k, mod) << endl;
	}
	return 0;
}