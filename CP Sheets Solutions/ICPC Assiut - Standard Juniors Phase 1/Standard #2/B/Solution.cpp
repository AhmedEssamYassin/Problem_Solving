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

	int N, Q;
	cin >> N >> Q;
	vector<int> Vec(N);
	for (int i{}; i < N; i++)
		cin >> Vec[i];

	/*
	- binary_search(first, last, val)
	returns true if found and false otherwise

	- lower_bound(first, last, val)
	returns an iterator to the first element that is greater than or equal to val (returns last if NOT found in range)

	- upper_bound(first, last, val)
	returns an iterator to the first element that is greater than val (returns last if NOT found in range)

	- (iterator - Vec.begin()) gives the 0-based index of the element

	- binary_search(), lower_bound() and upper_bound() STL functions work ONLY on in-ascending-order sorted ranges
	*/
	sort(Vec.begin(), Vec.end());

	string Query;
	int X;
	while (Q--)
	{
		cin >> Query >> X;
		if (Query == "binary_search")
		{
			if (binary_search(Vec.begin(), Vec.end(), X))
				cout << "found\n";
			else
				cout << "not found\n";
		}

		else if (Query == "lower_bound")
		{
			auto it = lower_bound(Vec.begin(), Vec.end(), X);
			if (it != Vec.end())
				cout << *it << endl;
			else
				cout << "-1\n";
		}

		else if (Query == "upper_bound")
		{
			auto it = upper_bound(Vec.begin(), Vec.end(), X);
			if (it != Vec.end())
				cout << *it << endl;
			else
				cout << "-1\n";
		}
	}

	return 0;
}