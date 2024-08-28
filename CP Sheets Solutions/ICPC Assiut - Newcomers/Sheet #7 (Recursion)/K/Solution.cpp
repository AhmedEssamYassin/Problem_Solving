#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll maxElement(const vector<ll> &arr, int idx)
{
	if (idx == arr.size())
		return LLONG_MIN;
	return max(arr[idx], maxElement(arr, idx + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		cout << maxElement(vc, 0);
	}
	return 0;
}