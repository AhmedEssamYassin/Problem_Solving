#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void arraySum(const vector<ll> &A, const vector<ll> &B, vector<ll> &out, int idx)
{
	if (idx == A.size())
		return;
	out[idx] = A[idx] + B[idx];
	arraySum(A, B, out, idx + 1);
}

void matrixSum(const vector<vector<ll>> &A, const vector<vector<ll>> &B, vector<vector<ll>> &out, int idx)
{
	if (idx == A.size())
		return;
	arraySum(A[idx], B[idx], out[idx], 0);
	matrixSum(A, B, out, idx + 1);
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
	int N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<vector<ll>> A(N, vector<ll>(M)), B(N, vector<ll>(M)), out(N, vector<ll>(M));
		for (int i{}; i < N; i++)
			for (int j{}; j < M; j++)
				cin >> A[i][j];

		for (int i{}; i < N; i++)
			for (int j{}; j < M; j++)
				cin >> B[i][j];

		matrixSum(A, B, out, 0);
		for (int i{}; i < N; i++)
			for (int j{}; j < M; j++)
				cout << out[i][j] << " \n"[j == M - 1];
	}
	return 0;
}