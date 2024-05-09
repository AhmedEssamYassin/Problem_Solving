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
	ll N;
	cin >> N;
	if (N == 1)
		return cout << 0, 0; // No Need to straight cuts, the whole pizza is a ONE piece

	if (N & 1) // If N is ODD, we need EXACTLY N straight cuts to get N equal pieces for them
		cout << N;
	else // If N is EVEN, we need ONLY N/2 straight cuts to get N equal pieces for them
		cout << N / 2;

	return 0;
}