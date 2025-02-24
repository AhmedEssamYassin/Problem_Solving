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
	int N, M;
	cin >> N >> M;
	vector<ll> A(N), B(M);
	for (int i{}; i < N; i++)
		cin >> A[i];
	for (int i{}; i < M; i++)
		cin >> B[i];

	ll countEqual{};
	ll cnt{}, mult{};
	int p = 0, q = 0; // To traverse the left and the right segment respectively
	while (p < N && q < M)
	{
		ll current = B[q];
		while (q < M && B[q] == current)
			mult++, q++;

		while (p < N && A[p] < current)
			p++;

		while (p < N && A[p] == current)
			cnt++, p++;

		countEqual += cnt * mult;
		cnt = 0, mult = 0;
	}

	cout << countEqual;
	return 0;
}
