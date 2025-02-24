#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int minimumIndex(vector<ll> &vc, ll X)
{
	int L{}, R = vc.size() - 1;
	int ans = vc.size() + 1;
	while (L <= R)
	{
		int mid = ((L + R) >> 1);
		if (vc[mid] >= X)
		{
			ans = mid + 1; // To be 1-based
			R = mid - 1;
		}
		else
			L = mid + 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int N, Q, X;
	cin >> N >> Q;
	vector<ll> vc(N);
	for (int i{}; i < N; i++)
		cin >> vc[i];
	while (Q--)
	{
		cin >> X;
		// The numbers are guaranteed to be sorted
		cout << minimumIndex(vc, X) << " ";
	}
	return 0;
}