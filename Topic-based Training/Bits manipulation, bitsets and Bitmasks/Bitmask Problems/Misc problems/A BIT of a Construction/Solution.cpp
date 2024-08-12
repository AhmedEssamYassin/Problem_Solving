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
	cin >> t;
	ll N, K;
	while (t--)
	{
		cin >> N >> K;
		if (N == 1)
		{
			cout << K << endl;
			continue;
		}
		int i{};
		cout << (__bit_floor(K) - 1) << " "; // The optimal number of ones we can get
		i++;
		K -= (__bit_floor(K) - 1);
		if (K) // If there is still some number != 0 to be printed
			cout << K << " ", i++;
		while (i++ < N)
			cout << 0 << " "; // Put all other element equal 0
		cout << endl;
	}
	return 0;
}