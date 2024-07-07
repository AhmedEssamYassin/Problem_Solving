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
	/*
	We can make the observation that only the first 31 elements matter,
	Since after placing them optimally we can be sure all bits that could be set in the prefix OR would have already been set.
	So, we can brute force the optimal choice for the first 31 elements
	(We choose to add an element if it provides the largest new prefix OR value among all unused elements)
	and then just add the rest of the unused elements.
	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<int> arr(N);
		for (int i{}; i < N; i++)
			cin >> arr[i];

		int OR{};
		bitset<2000'01> Vis;
		int K = min(31LL, N);
		for (int i{}; i < K; i++)
		{
			int Max{}, idx = -1;
			for (int j{}; j < N; j++)
			{
				if (!Vis[j])
				{
					if ((OR | arr[j]) > Max)
					{
						Max = (OR | arr[j]);
						idx = j;
					}
				}
			}
			OR |= arr[idx];
			Vis[idx] = 1;
			cout << arr[idx] << " ";
		}
		for (int i{}; i < N; i++)
		{
			if (!Vis[i])
				cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}