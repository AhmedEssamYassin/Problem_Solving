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
	ll N, x;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		/*
		For each bulb, it will change color to blue iff all the previous bulbs are turned on.
		- Give each bulb a value from 1 to N (1, 2, 3,..., N)
		- let's make a variable to keep track of turned on bulbs: ll sum{};
		- For each bulb X, add its value to the summation: sum += X;
		- Keep track of the rightmost bulb turned on, let's call it 'last'
		- For a bulb, in order to change its color to blue, the following condition MUST be satisfied: sum == last * (last + 1) / 2
		because that means that ALL bulbs in range [1, last] are now turned on so the last bulb should change its color to blue
		*/
		ll sum{}, cnt{}, last = INT_MIN;
		for (int i{}; i < N; i++)
		{
			cin >> x;
			last = max(x, last);
			sum += x;
			if (sum == last * (last + 1) / 2)
				cnt++;
		}
		cout << cnt;
	}
	return 0;
}
