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
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, K;
	// cin >> t;
	while (t--)
	{
		/*
		We want to count the pairs with total sum K, which is a standard frequency problem
		At each number arr[i], we need to know the frequency of (K - arr[i])
		*/
		cin >> N >> K;
		int *arr = new int[N];
		map<ll, int> freq;

		ll cnt{};
		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			cnt += freq[K - arr[i]];
			freq[arr[i]]++;
		}
		cout << cnt << endl;
		delete[] arr;
	}
	return 0;
}
