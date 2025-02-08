#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int mod = 1e9 + 7;
// Kadane's Algorithm to Maximum Sum Sub_array
// At each element: Either start a new contiguous sub_array or continue the previous sum
ll MaxSubArraySum(ll *arr, int size)
{
	ll Max_sub_sum = 0, curr_sum = 0;
	for (int i{}; i < size; i++)
	{
		curr_sum += arr[i];
		if (curr_sum > Max_sub_sum)
			Max_sub_sum = curr_sum;

		if (curr_sum < 0)
			curr_sum = 0;
	}
	return Max_sub_sum;
}

ll modBinExp(ll N, int power, int m)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = (res % m * N % m) % m;
		N = (N % m * N % m) % m;
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
	int t = 1;
	cin >> t;
	ll N, K;
	while (t--)
	{
		cin >> N >> K;
		ll *arr = new ll[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		ll maxSum{};
		maxSum = MaxSubArraySum(arr, N);

		ll ans{};
		for (int i{}; i < N; i++)
			ans += arr[i];
		ll val = (modBinExp(2, K, mod) - 1 + mod) % mod;
		ans = ((ans % mod + mod) % mod + (__int128_t(val) * maxSum % mod) % mod) % mod;
		ans = (ans % mod + mod) % mod;
		cout << ans << endl;
		delete[] arr;
	}
	return 0;
}