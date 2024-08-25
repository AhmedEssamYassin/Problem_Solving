#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<vector<ll>> memo;
ll dp(const vector<ll> &a, ll coins, ll K, int idx, ll bad)
{
	if (idx == a.size())
		return coins;

	if (bad > 32)
		return coins; // No more chests with value > 0 to try on
	ll &ret = memo[idx][bad];
	if (~ret)
		return ret;
	// Good key
	ll choice1 = dp(a, coins - K + a[idx] / (1LL << (bad)), K, idx + 1, bad);
	// Bad key
	ll choice2 = dp(a, coins + a[idx] / (1LL << (bad + 1)), K, idx + 1, bad + 1);
	return ret = max(choice1, choice2);
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
	A bad key, which does not cost any coins, but will halve all the coins in each unopened chest, including the chest it is about to open.
	The halving operation will round down to the nearest integer for each chest halved.
	that means if we use a bad key at idx 2, all elements in [2, N - 1], will be divided by 2
	and if we use a bad key at idx 3, all elements in [3, N - 1], will be divided by 2
	but elements [3, N - 1] were divided by 2 previously, so now they are divided by 4
	and so on.
	Denote number of bad keys as x
	we notice that, at current chest, we use (value / (1LL << x))
	That means after 31 bad keys, all coming chests will have a value of 0, because they are bounded to approximately (1LL << 31)

	This is a standard dp, subset style problem with memoization
	We can memoize on the index which is bounded to the length of the array, and the number of bad keys <= 31
	which fits perfectly in memory.
	*/
	int t = 1;
	ll N, K;
	cin >> t;
	while (t--)
	{
		cin >> N >> K;
		memo.clear();
		memo.resize(N + 1, vector<ll>(35, -1));
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		cout << dp(a, 0, K, 0, 0) << endl;
	}
	return 0;
}