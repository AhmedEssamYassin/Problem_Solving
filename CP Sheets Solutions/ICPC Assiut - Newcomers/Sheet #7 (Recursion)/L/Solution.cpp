#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll arraySum(const vector<ll> &arr, int idx)
{
	if (idx == arr.size())
		return 0;
	return (arr[idx] + arraySum(arr, idx + 1));
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
		cout << arraySum(vc, 0);
	}
	return 0;
}