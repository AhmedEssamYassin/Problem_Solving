#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	/*
	You are given an array consisting of N positive integers.
	Find a NON-empty subset of its elements such that their sum is EVEN (i.e. divisible by 2) or determine that there is NO such subset.
	- If there exists at least one EVEN number, it's a valid subset
	- If there exists at least two ODD numbers, any EVEN number of elements between them form a valid subset
	  because The sum of EVEN number of ODD elements Yields an EVEN sum
	- If NONE of previous cases is found, there is NO such subset
	*/
	int t, N, X;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<pair<int, uint32_t>> ODDs;
		vector<pair<int, uint32_t>> EVENs;
		for (int i{1}; i <= N; i++)
		{
			cin >> X;
			if (X & 1) // ODD
				ODDs.push_back({X, i});
			else // EVEN
				EVENs.push_back({X, i});
		}
		if (!EVENs.empty())
			cout << 1 << endl
				 << EVENs[0].second << endl;
		else if (ODDs.size() >= 2)
			cout << 2 << endl
				 << ODDs[0].second << " " << ODDs.back().second << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}