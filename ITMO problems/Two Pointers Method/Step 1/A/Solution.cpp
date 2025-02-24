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
	vector<ll> A(N), B(M), vc(N + M);
	for (int i{}; i < N; i++)
		cin >> A[i];
	for (int i{}; i < M; i++)
		cin >> B[i];

	int p = 0, q = 0; // To traverse the left and the right segment respectively
	vector<ll> temp;
	for (int i = 0; i < N + M; i++)
	{
		if (p >= N) // First segment comes to an end
			temp.push_back(B[q++]);
		else if (q >= M) // Second segment comes to an end
			temp.push_back(A[p++]);
		else if (A[p] <= B[q]) // The first segment has the smaller element
			temp.push_back(A[p++]);
		else // The second segment has the smaller element
			temp.push_back(B[q++]);
	}

	// Overwriting the original elements in a sorted manner
	for (int i = 0; i < temp.size(); i++)
		vc[i] = temp[i];
	for (int i = 0; i < N + M; i++)
		cout << vc[i] << " ";
	return 0;
}