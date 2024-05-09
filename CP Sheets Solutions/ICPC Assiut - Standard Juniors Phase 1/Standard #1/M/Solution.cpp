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

	vector<int> Vec(N);
	for (int i = 0; i < N; i++)
		cin >> Vec[i];

	sort(Vec.begin(), Vec.end()); // Sorting numbers in ascending order

	Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end()); // removing all duplicates

	while (Q--)
	{
		cin >> X;
		auto it = lower_bound(Vec.begin(), Vec.end(), X);
		uint32_t index = it - Vec.begin();
		/*
		- To get the 0-based index of the value X in the vector iff exists
		- To get the SUPPOSED-TO-BE 0-based index of the value X in the vector if it does NOT exist
		Example:
		index: 0 1 2 3 4
		Vec[]: 1 3 4 5 6
		if X = 8 --> (lower_bound(first, last, X) - Vec.begin()) will be 5
		if X = 2 --> (lower_bound(first, last, X) - Vec.begin()) will be 1
		*/
		int Less_than_cnt = index;
		int Greater_than_cnt = Vec.size() - index - (*it == X); // If the number is ALREADY existing

		cout << Less_than_cnt << " " << Greater_than_cnt << endl;
	}

	return 0;
}