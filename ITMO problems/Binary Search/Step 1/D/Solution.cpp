#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int maximumIndex(vector<ll> &vc, ll X)
{
	int L{}, R = vc.size() - 1;
	int ans{};
	while (L <= R)
	{
		int mid = ((L + R) >> 1);
		if (vc[mid] <= X)
		{
			ans = mid + 1; // To be 1-based
			L = mid + 1;
		}
		else
			R = mid - 1;
	}
	return ans;
}

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
	int N, Q, L, R;
	cin >> N;
	vector<ll> vc(N);
	for (int i{}; i < N; i++)
		cin >> vc[i];
	sort(vc.begin(), vc.end());
	cin >> Q;
	while (Q--)
	{
		cin >> L >> R;
		int start = minimumIndex(vc, L);
		int end = maximumIndex(vc, R);
		cout << end - start + 1 << " ";
	}
	return 0;
}