#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// #define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	Let's try to subtract 1, 2, 4, ... . i.e., (1, 2¹, 2², 2³ ...)
	In other words, we will iterate over k = 0, 1, 2, ..., and subtract (1LL << k)
	and we stop when the initial count of bits becomes 0 (let's call it initCnt)
	We have ONLY two cases:
	1. This bit is already in the original N, so that means the (cnt - newCnt = 1)
	   Then we just set that bit in the answer
	   and we decrease initCnt by 1 iff there was NO shift (we will know it later)

	2. This bit is NOT set in the original N, that means (cnt - newCnt != 1)
	   But that means, there will be another set bit with position m, where m > k
	   then we need to set this bit m, how do we obtain it?
	   Suppose we have the number 24, which is 11000
	   11000 - 00001 = 10111
	   here m = 3, k = 0, cnt = 2, newCnt = 4
	   subtracting 1 from a number flips all bits from the first set bit to the LSB inclusive
	   that means distance between m and k EXCLUSIVE, i.e., (m - k - 1) is the same as difference in ones count
	   m - k - 1 = newCnt - cnt
	   So, m = k + 1 + newCnt - cnt
	   and we set that m bit (ans |= (1LL << m))
	   Also, we decrease initCnt by 1 and make shift = true
	   so that when we reset coming bits, we know it's now set in N because of previous subtraction
	   NOT because it was existing from the very beginning!
	*/
	int t = 1;
	ll N, cnt;
	cin >> t;
	while (t--)
	{
		auto Ask = [&](ll k)
		{
			cout << "- " << k;
			cout << endl;
			ll x;
			cin >> x;
			return x;
		};
		cin >> cnt;
		ll ans{}, initCnt = cnt;
		bool shift = false;
		for (int k{}; k < 30 && initCnt > 0; k++)
		{
			ll newCnt = Ask((1LL << k));
			if (cnt - newCnt == 1)
			{
				if (!shift)
					initCnt--, ans |= (1LL << k);
			}
			else
			{
				ll m = k + 1 + newCnt - cnt;
				ans |= (1LL << m);
				initCnt--;
				shift = true;
			}
			cnt = newCnt;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}