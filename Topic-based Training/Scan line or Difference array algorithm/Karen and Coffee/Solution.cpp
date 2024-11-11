#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, m, q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> m >> q;
		int NumOfOccurrences[2000000], Admissible_Temp_till_now[2000000];
		while (N--)
		{
			ll L, R;
			cin >> L >> R;
			NumOfOccurrences[L]++;
			NumOfOccurrences[R + 1]--;
		}
		// 91 94
		// 92 97
		// 97 99
		// Scan line on the whole range to count the number of occurrences in all intervals
		// 90 91 92 93 94 95 96 97 98 99 100
		// 0  1  0  0  0  -1  0  0  0  0  0
		// 0  1  1  0  0  -1  0  0 -1  0  0
		// 0  1  1  0  0  -1  0  1 -1  0 -1
		for (int i = 1; i < 2000000; i++)
		{
			NumOfOccurrences[i] += NumOfOccurrences[i - 1];
			// 0  1  2  2  2   1  1  2  1  1  0
			Admissible_Temp_till_now[i] += Admissible_Temp_till_now[i - 1] + (NumOfOccurrences[i] >= m);
		}
		while (q--)
		{
			ll a, b;
			cin >> a >> b;
			cout << Admissible_Temp_till_now[b] - Admissible_Temp_till_now[a - 1] << "\n";
		}
	}
	return 0;
}