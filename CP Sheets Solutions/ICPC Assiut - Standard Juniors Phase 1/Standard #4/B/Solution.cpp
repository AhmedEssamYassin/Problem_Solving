#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Is_possible(vector<int> &V, int mid, int Cows)
{
	int Positioned_cows{1}; // Put a cow into the first stall
	int current = V[0];
	for (int i{1}; i < V.size(); i++)
	{
		if (V[i] - current >= mid)
		{
			Positioned_cows++;
			if (Positioned_cows == Cows)
				return true;
			current = V[i];
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int N, C, X;
	cin >> N >> C;
	vector<int> Vec(N);
	for (int i{}; i < N; i++)
		cin >> Vec[i];
	sort(Vec.begin(), Vec.end()); // To apply binary search

	// 5 3
	// 1 2 4 8 9
	// Find the greatest minimum distance.
	int ans;
	ll L = 0, R = 2e9;
	while (L <= R)
	{
		ll mid = L + (R - L) / 2;
		if (Is_possible(Vec, mid, C))
		{
			ans = mid;	 // A candidate answer
			L = mid + 1; // Search for a better (greater) minimum distance
		}
		else
			R = mid - 1; // Search for a valid greatest minimum distance
	}
	cout << ans;

	return 0;
}