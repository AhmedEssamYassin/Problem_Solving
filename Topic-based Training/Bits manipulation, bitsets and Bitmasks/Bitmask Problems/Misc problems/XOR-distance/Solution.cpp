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
	ll N, a, b, r;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> r;
		ll XOR{};
		if (a > b)
			swap(a, b); // To guarantee that a <= b
		/*
		Suppose a <= b
		If two bits are the same in a and b, they will definitely be 0 in |(a ^ x) - (b ^ x)|
		and it's better to make that bit 0 in x because we need x <= r

		If two bits are different in a and b:
		- If the bit is set in b but not set in a
		leave the first MSB to be set in b (making that bit 0 in x) to assert that b >= a still holds
		and make all other bits of that kind be set in a and cleared in b (making that bit 1 in x)
		That minimizes the difference between the two numbers (a ^ x) and (b ^ x)
		*/
		bool first{true};
		for (ll i{62}; i >= 0; i--)
		{
			if (not(a & (1LL << i)) && (b & (1LL << i))) // Set in b but not in a
			{
				if (first)
					first = false;
				else
					XOR |= (1LL << i) * ((XOR | (1LL << i)) <= r);
			}
		}
		cout << abs((a ^ XOR) - (b ^ XOR)) << endl;
	}
	return 0;
}