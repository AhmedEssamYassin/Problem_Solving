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

	int N, K;
	cin >> N >> K;
	int *arr = new int[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	int Minimum = INT_MAX, cnt{};
	for (int i{}; i < N; i++)
	{
		Minimum = min(Minimum, arr[i]);
		cnt++;

		if (cnt == K || i == N - 1) // If reached a window of size K or reached the end of array
		{
			cout << Minimum << " ";
			cnt = 0;
			Minimum = INT_MAX;
		}
	}
	delete[] arr;

	return 0;
}