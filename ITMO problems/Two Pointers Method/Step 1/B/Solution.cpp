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
	vector<ll> A(N), B(M), vc(M);
	for (int i{}; i < N; i++)
		cin >> A[i];
	for (int i{}; i < M; i++)
		cin >> B[i];

	ll countSmaller{};
	int p = 0, q = 0; // To traverse the left and the right segment respectively
	for (int i = 0; i < N + M; i++)
	{
		if (p >= N)			// First segment comes to an end
			vc[q] = N, q++; // Every element now is greater than the whole first array

		else if (q >= M) // Second segment comes to an end
			break;

		else if (A[p] < B[q]) // The first segment has the smaller element
			vc[q] = ++p;

		else // The second segment has the smaller element
			vc[q++] = p;
	}

	for (int i = 0; i < M; i++)
		cout << vc[i] << " ";
	return 0;
}