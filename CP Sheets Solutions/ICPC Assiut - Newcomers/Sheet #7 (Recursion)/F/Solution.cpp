#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void printEvenIndices(const vector<ll> &arr, int N)
{
	if (N < 0)
		return;
	N--;
	if (N % 2 == 0)
		cout << arr[N] << " ";
	printEvenIndices(arr, N);
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
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N; // Number of lines
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		printEvenIndices(vc, N);
	}
	return 0;
}