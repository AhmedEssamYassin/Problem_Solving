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
	int t = 1, N, M, X;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		int *Freq_arr{new int[M + 1]{0}};
		for (int i{}; i < N; i++)
		{
			cin >> X;
			Freq_arr[X]++;
		}

		for (int i{1}; i <= M; i++)
			cout << Freq_arr[i] << endl;

		// Freeing memory
		delete[] Freq_arr;
	}

	return 0;
}