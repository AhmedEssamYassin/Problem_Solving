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
#endif // !ONLINE_JUDGE

	int N, Q, X;
	cin >> N >> Q;
	vector<pair<int, int>> Vec(N);
	for (int i{}; i < N; i++)
		cin >> Vec[i].first >> Vec[i].second;
	// sort(Vec.begin(), Vec.end()); // The given input is guaranteed to be sorted

	string Query;
	pair<int, int> P;
	while (Q--)
	{

		cin >> Query >> P.first >> P.second;
		if (Query == "find")
		{
			if (binary_search(Vec.begin(), Vec.end(), P))
				cout << "found\n";
			else
				cout << "not found\n";
		}

		else if (Query == "lower") // Farthest (last) pair that is less than P (0-based)
		{
			auto it = lower_bound(Vec.begin(), Vec.end(), P);
			// returns an iterator to the first pair that is greater than or equal to P
			// (it - Vec.begin()) evaluates the 0-based index of that element, let's call it idx
			// The preceding element to that Vec[idx] is the Farthest (last) pair that is less than P (0-based)
			// If the found element is at idx = 0 that means NO existing element is less than P, then we should print -1
			// So it turns out that (it - Vec.begin() - 1) will always be the answer
			cout << (it - Vec.begin() - 1) << endl;
		}

		else if (Query == "upper") // Nearest (first) pair that is greater than P (0-based)
		{
			auto it = upper_bound(Vec.begin(), Vec.end(), P);
			// returns an iterator to the first pair that is greater than P
			// (it - Vec.begin()) evaluates the 0-based index of that element, let's call it idx
			// If the found iterator is Vec.end() that means NO existing element is greater than P, then we should print -1
			if (it != Vec.end())
				cout << (it - Vec.begin()) << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}