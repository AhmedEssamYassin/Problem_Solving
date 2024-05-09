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
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int L = 0, R = N - 1; L <= R; L++, R--)
	{
		if (arr[L] != arr[R])
		{
			delete[] arr; // Freeing memory before termination in order NOT to have a memory leak
			return cout << "NO", 0;
		}
	}
	cout << "YES";
	delete[] arr;
	return 0;
}