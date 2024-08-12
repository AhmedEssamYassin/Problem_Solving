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
	We can maintain a frequency of all elements from 1 to N until half of the array (N)
	Then we have three cases:

	1. If some element occurs 0 times in this half, that means it occurs 2 times in the other half
	Push it twice in R
	2. If some element occurs 1 time in this half, that means it occurs 1 time in the other half
	Push it once in L and once in R
	3. If some element occurs 2 times in this half, that means it occurs 0 times in the other half
	Push it twice in L

	The idea here is that every element that occur twice will have XOR = 0
	that means all elements that occurred twice are insignificant in XOR evaluation
	and of course element that occurred once in both halves are evenly distributed making the XOR equal
	*/
	int t = 1;
	ll N, K;
	cin >> t;
	while (t--)
	{
		cin >> N >> K;
		vector<ll> vc(2 * N), L, R, freq(N + 1, 0);
		for (int i{}; i < 2 * N; i++)
			cin >> vc[i];
		for (int i{}; i < N; i++)
			freq[vc[i]]++;
		K <<= 1;
		vector<ll> g0, g1, g2;
		for (int i = 1; i <= N; i++)
		{
			if (freq[i] == 0)
				g0.push_back(i);
			else if (freq[i] == 1)
				g1.push_back(i);
			else
				g2.push_back(i);
		}

		for (const ll &x : g2)
		{
			if (L.size() < K)
				L.push_back(x), L.push_back(x);
		}
		for (const ll &x : g1)
		{
			if (L.size() < K)
				L.push_back(x);
		}

		for (const ll &x : g0)
		{
			if (R.size() < K)
				R.push_back(x), R.push_back(x);
		}
		for (const ll &x : g1)
		{
			if (R.size() < K)
				R.push_back(x);
		}

		for (const ll &num : L)
			cout << num << " ";
		cout << endl;
		for (const ll &num : R)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}