#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> concatenate(const vector<ll> &A, const vector<ll> &B)
{
	int n = A.size();
	vector<ll> C(2 * n);
	int j = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (i < n)
			C[i] = B[i];
		else
			C[i] = A[j++];
	}
	return C;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N), b(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		for (int i{}; i < N; i++)
			cin >> b[i];
		vector<ll> C = concatenate(a, b);
		for (int i{}; i < 2 * N; i++)
			cout << C[i] << " ";
	}
	return 0;
}