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
	(N + 1) flips ALL bits after the rightmost cleared bit of N, including the rightmost cleared bit
	So, going from L to R meaning adding 1 each time getting (L + 1), (L + 2),..., R
	Every time we add 1, we flip ALL bits after the rightmost cleared bit of previous number, including the rightmost cleared bit

	If [L, R] = [301, 323]

	100101101
	100101110
	100101111
	100110000
	100110001
	100110010
	100110011
	100110100
	100110101
	100110110
	100110111
	100111000
	100111001
	100111010
	100111011
	100111100
	100111101
	100111110
	100111111
	101000000
	101000001
	101000010
	101000011

	We can see that ALL numbers from L to R will have a common prefix,
	that means the XOR of any pair in range [L, R] will have the bits of this prefix cleared
	i.e., for the XOR of any two numbers to be maximum value, their MSB will be fixed and it is the MSB in (L ^ R)

	Observing the technique to get MSB, we can see that the MSB of (L ^ R) will tells us the maximum value we can achieve
	i.e., Let (L ^ R) be 1xxxx where x can be either 0 or 1
	then, the maximum XOR value we can get is 11111 by making ALL x's be set
	since numbers from L to R have ALL possible combinations of xxxx, it is always possible to choose these bits optimally.
	*/
	int t = 1;
	ll L, R;
	// cin >> t;
	while (t--)
	{

		cin >> L >> R;
		if (L == R)
			return cout << 0, 0;

		ll val = (L ^ R);
		int MSB = 63 - __builtin_clzll(val);
		cout << (1LL << (MSB + 1)) - 1;
	}
	return 0;
}