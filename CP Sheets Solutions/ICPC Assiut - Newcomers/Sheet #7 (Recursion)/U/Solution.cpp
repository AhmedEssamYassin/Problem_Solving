#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct __item
{
	ll wight, value;
};

ll knapSack(const vector<__item> &items, ll W, int idx)
{
	if (W < 0)
		return -items[idx - 1].value; // Invalidate this case, Undo previous transition
	if (idx == items.size())
		return 0; // Neutral value

	ll Pick = items[idx].value + knapSack(items, W - items[idx].wight, idx + 1);
	ll Leave = knapSack(items, W, idx + 1);
	return max(Pick, Leave);
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
	ll N, W;
	// cin >> t;
	while (t--)
	{
		cin >> N >> W;
		vector<__item> items(N);
		for (int i{}; i < N; i++)
			cin >> items[i].wight >> items[i].value;
		cout << knapSack(items, W, 0);
	}
	return 0;
}