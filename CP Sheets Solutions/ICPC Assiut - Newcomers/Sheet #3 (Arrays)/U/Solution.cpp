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
	int t = 1, N, M;
	// cin >> t;
	while (t--)
	{
		/*
		A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
		To check if B is a subsequence of A, we must find ALL elements of B in A and they must appear in order
		*/
		cin >> N >> M;
		int *A = new int[N];
		int *B = new int[M];
		for (int i{}; i < N; i++)
			cin >> A[i];

		for (int i{}; i < M; i++)
			cin >> B[i];

		int j = 0, cnt = 0;
		for (int i = 0; i < M; i++) // To traverse B
		{
			for (NULL; j < N; j++) // To traverse A
			{
				if (B[i] == A[j])
				{
					cnt++;
					j++;
					break;
				}
			}
		}
		if (cnt == M) // If ALL elements of B were found
			cout << "YES";
		else
			cout << "NO";
		// Freeing memory
		delete[] B;
		delete[] A;
	}

	return 0;
}