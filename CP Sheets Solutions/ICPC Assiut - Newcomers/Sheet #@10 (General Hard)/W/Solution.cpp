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
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		/*
		For every pair ( A[i] , A[j] ) for all (1 <= i,j <= N) such that arr[i] <= arr[j]
		he will calculate this equation (j - i)
		After he calculates all equations he needs to find what is the maximum value he can get

		The problem requires finding the Farthest pair such that arr[i] <= arr[j] for every (i <= j)
		because if NOT, (j - i) would yield a negative value, which is absolutely NOT the maximum
		*/
		cin >> N;
		int *arr = new int[N];
		priority_queue<pair<int, int>> prQue;
		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			prQue.push({arr[i], i}); // To push them sorted on basis of first element in pairs (which is the value of arr[i])
		}

		int ans = INT_MIN;
		for (int i{}; i < N; i++)
		{
			while (arr[i] <= prQue.top().first && !prQue.empty())
			{
				ans = max(ans, prQue.top().second - i);
				prQue.pop();
			}
		}
		cout << ans;
		delete[] arr;
	}
	return 0;
}
