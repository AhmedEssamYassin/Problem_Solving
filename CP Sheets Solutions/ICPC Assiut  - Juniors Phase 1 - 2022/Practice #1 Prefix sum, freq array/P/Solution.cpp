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
		cin >> N >> K;
		int *d = new int[N];
		int freq[101] = {0};
		for (int i{}; i < N; i++)
			cin >> d[i], freq[d[i] %= K]++; // Storing the frequency of numbers under modulo K

		/*
		In order for K | (d[i] + d[j]), d[i] % K + d[j] % K = either 0 of K
		All the zero mods can be paired together without repetition, so they form freq[0]/2 valid pair
		Each modulo (i) makes a valid pair with the modulo (K - i) , 1 <= i < K
		Except when (i = K - i) we are pairing the number with itself so we should divide that count by 2
		Also don't forget to decrease the frequency in order NOT to double count the pairs
		The answer is obviously 2 * (freq[0] / 2) + 2 * ∑ (min(freq[i], freq[K - i]))
		We multiplied by 2 because we need the number of boxes NOT the number of pairs.
		*/
		int cnt{};
		cnt += 2 * (freq[0] / 2);
		for (int i{1}; i < K; i++)
		{
			int val = min(freq[i], freq[K - i]);
			cnt += 2 * (val / (i == K - i ? 2 : 1));
			freq[i] -= val, freq[K - i] -= val;
		}

		cout << cnt;
		delete[] d;
	}
	return 0;
}
