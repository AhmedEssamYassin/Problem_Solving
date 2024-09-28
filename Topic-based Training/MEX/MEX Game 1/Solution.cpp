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
	ll N, X;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<int> freq(N + 1, 0);
		for (int i{}; i < N; i++)
			freq[cin >> X, X]++;

		// Alice wants to maximize the MEX while Bob wants to minimize the MEX
		int cnt{0};
		for (int i{}; i < N + 1; i++)
		{
			// 0 0 1 4 4 3
			// Alice will prefer to take the minimum element which appears 1 times first
			// Because if she leaves it, Bob will take it, and this minimizes the answer
			cnt += (freq[i] == 1); // That element CANNOT be compensated, Alice will take it if it's her turn
			// Note, if the frequency of an element, not existing in the array, is zero
			// in an imaginary situation where Alice can choose the whole array, that element will still be the MEX, so it's the answer
			if (cnt == 2 || freq[i] == 0)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}