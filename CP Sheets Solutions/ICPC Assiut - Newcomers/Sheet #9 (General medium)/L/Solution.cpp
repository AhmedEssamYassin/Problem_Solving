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
		cin >> N;
		int *arr = new int[N];
		map<int, int> mp;

		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			mp[arr[i]]++;
		}

		int cnt{};
		for (auto &[difficulty, problemCnt] : mp)
			if (problemCnt > 1)
				cnt += problemCnt - 1;
		cout << (cnt > 0 ? cnt : -1);
	}
	return 0;
}
