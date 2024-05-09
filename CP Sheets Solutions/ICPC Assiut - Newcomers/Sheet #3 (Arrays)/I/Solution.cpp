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
	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];
		int Min_ans{INT_MAX};
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
				Min_ans = min(Min_ans, arr[i - 1] + arr[j - 1] + j - i);
		}
		cout << Min_ans << endl;
		delete[] arr;
	}
	return 0;
}