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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		int N, Sock;
		cin >> N;
		vector<ll> freq(N + 1, 0); // Frequency array
		// 2 1 1 3 2 3

		ll cnt{};
		ll Max_on_table = INT_MIN;
		for (int i{}; i < 2 * N; i++)
		{
			cin >> Sock;
			freq[Sock]++; // Update frequency

			if (freq[Sock] == 1) // If it's NOT yet paired, that means it's on the table, Increment cnt by one
				cnt++;
			else if (freq[Sock] == 2) // If it's paired, that means it will be moved to wardrobe, Decrement cnt by one
				cnt--;

			Max_on_table = max(Max_on_table, cnt); // Store the maximum value cnt will reach
		}
		cout << Max_on_table;
	}
	return 0;
}
