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
	ll N;
	// cin >> t;
	while (t--)
	{
		/*
		Let's record the frequency of character 'a' and 'b' at each position i
		Let's iterate through the string with two pointers i and j (Nested loop: O(N²) fits in time)
		Out of all i's and j's, we take the maximum possible cut as follows:
		pref_a until i + pref_b from i to j + pref_a from j to N
		*/
		string str;
		cin >> str;
		N = str.length();
		int *pref_a{new int[N]{0}};
		int *pref_b{new int[N]{0}};

		pref_a[0] += (str[0] == 'a');
		pref_b[0] += (str[0] == 'b');

		for (int i{1}; i < N; i++)
		{
			pref_a[i] += pref_a[i - 1] + (str[i] == 'a');
			pref_b[i] += pref_b[i - 1] + (str[i] == 'b');
		}

		int maxAns{-1};
		for (int i{}; i < N; i++)
		{
			for (int j{i}; j < N; j++)
				maxAns = max(maxAns, (i > 0 ? pref_a[i - 1] : 0) + (pref_b[j] - (i > 0 ? pref_b[i - 1] : 0)) + (pref_a[N - 1] - (j > 0 ? pref_a[j - 1] : 0)));
		}
		cout << maxAns << endl;
		delete[] pref_b;
		delete[] pref_a;
	}
	return 0;
}
