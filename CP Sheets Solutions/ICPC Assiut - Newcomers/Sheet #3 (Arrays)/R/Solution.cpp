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
#endif // !ONLINE_JUDGE
	int t = 1, N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		int *A = new int[N];
		int *B = new int[N];

		for (int i{}; i < N; i++)
			cin >> A[i];

		for (int i{}; i < N; i++)
			cin >> B[i];

		if (is_permutation(A, A + N, B))
			cout << "yes";
		else
			cout << "no";
		delete[] B;
		delete[] A;
	}

	return 0;
}