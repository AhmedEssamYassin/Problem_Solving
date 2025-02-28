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
		The maximum total profit achieved in K days is obviously the summation of the biggest K difficulties.
		But the problem is how to distribute these problems in such a way that makes each of the K maximum difficulties be in a separate day?
		Extract K largest values of the given array and place a separator right after each of them (except the rightmost one).
		The problem is we can't directly delete a number if it's one of the maximums, why?
		because it may be repeated with some occurrence.
		Example:
		1 6 2 6
		we can choose 6 and 6
		when we separate [1, 6] we CANNOT delete 6 from the chosen set, because we must choose it again!
		Let's make a frequency for each of the maximums and delete it iff that frequency becomes 0.
		*/
		cin >> N >> K;
		vector<int> arr(N), C_arr;
		for (int i{}; i < N; i++)
			cin >> arr[i];
		C_arr = arr;

		sort(arr.begin(), arr.end()); // Sorting to get the K maximum difficulties

		ll sum{};
		set<int> K_max;
		int freq[2001] = {0};
		for (int i{N - 1}, j{}; i >= 0 && j < K; i--, j++)
			sum += arr[i], K_max.insert(arr[i]), freq[arr[i]]++;

		cout << sum << endl;

		int i, len, j = 0;
		for (i = 0, len = 1; i < N && j < K - 1; i++, len++)
		{
			if (K_max.find(C_arr[i]) != K_max.end()) // If that number is one of the chosen difficulties
			{
				freq[C_arr[i]]--;
				if (freq[C_arr[i]] == 0)
					K_max.erase(C_arr[i]);
				cout << len << " ";
				len = 0;
				j++;
			}
		}
		if (N - i) // The partition containing the rightmost one of the K maximum numbers
			cout << (N - i);
	}
	return 0;
}
