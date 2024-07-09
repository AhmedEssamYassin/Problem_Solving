#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void shiftArray(vector<ll> &a)
{
	int N = a.size();
	vector<ll> shiftedArray(N);
	shiftedArray[0] = a[N - 1];

	for (int i = 1; i < N; i++)
		shiftedArray[i] = a[i - 1];
	for (int i = 0; i < N; i++)
		a[i] = shiftedArray[i];
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
	ll N, X;
	// cin >> t;
	while (t--)
	{
		cin >> N >> X;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		while (X--)
			shiftArray(a);
		for (int i{}; i < N; i++)
			cout << a[i] << " ";
	}
	return 0;
}