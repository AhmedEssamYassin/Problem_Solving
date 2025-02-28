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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		int *freq{new int[200007]{0}};
		/*
		Since each child will be given EXACTLY 2 sweets
		and we want to give the maximum possible number of children equal shares of sweets
		The problem reduces to find the most frequent sum out of ALL possible pairs!
		*/
		cin >> N;
		vector<int> V(N);
		for (int i{}; i < N; i++)
			cin >> V[i];
		for (int i{}; i < N; i++)
		{
			for (int j{i + 1}; j < N; j++)
				freq[V[i] + V[j]]++;
		}
		cout << *max_element(freq, freq + 200007);
		delete freq;
	}
	return 0;
}
