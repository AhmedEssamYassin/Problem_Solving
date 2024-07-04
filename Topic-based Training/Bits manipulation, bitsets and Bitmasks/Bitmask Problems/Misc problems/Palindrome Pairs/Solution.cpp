#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

template <typename T>
void Flip_ith_bit(T &N, short int i) // 0-based
{
	// 111001010(1)1 ^ 000000000(1)0 = 111001010(0)1
	N = (N ^ (T(1) << i));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	For a string to have the capability of being reordered to become a palindrome:
	1. If length is EVEN: ALL characters MUST have EVEN occurrence
	2. If length is ODD : ALL characters MUST have EVEN occurrence EXCEPT the middle character should have ODD occurrence

	- Let's make a Bitmask of 26 bits (an int32 is enough or any bigger type)
	to represent Parity of the occurrence of each character

	- Let the OFF state of a bit (a cleared bit) represent the EVEN occurrence
	- Let the ON state of a bit (a set bit) represent the ODD occurrence
	As ODD parity and EVEN parity alternate with each increment
	i.e., (ODD + 1 = EVEN) and (EVEN + 1 = ODD)
	A bit representing the occurrence of a character needs to be flipped with each occurrence

	At the end:
	-----------
	1. If ALL characters have EVEN occurrence, i.e., the Bitmask = 0
	then it can be reordered to form a palindrome

	2. If ALL characters have EVEN occurrence EXCEPT the middle character should have ODD occurrence
	i.e., Bitmask should has a single bit ON (set), then it also can be reordered to form a palindrome

	Now when we concatenate two strings, we just add the occurrences of both of them
	ODD + EVEN = ODD (1 ^ 0 = 1)
	EVEN + ODD = ODD (0 ^ 1 = 0)
	EVEN + EVEN = EVEN (0 ^ 0 = 0)
	ODD + ODD = EVEN (1 ^ 1 = 1)
	We can obviously see that the bitwise XOR operation represents the concatenation here

	Now, how we count?
	If we look carefully, we would se that we are interested in two types of bitmasks
	- All cleared bitmask: 00000000000000000000000000
	- A bitmask having 1 set bit: which have 26 different possibilities
	So we have 27 different possibilities, we can iterate over all of them

	So, (a[i] ^ a[j]) = C, where C is one of the 27 possibilities
	Fix a[i], XOR both sides with a[i], we get (C ^ a[i]) = a[j]
	So we need to count how many a[j] exists for every possible (C ^ a[i]) where C has 27 possibilities
	*/
	int t = 1;
	ll N, k;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		map<ll, ll> mp;
		string str;
		ll cnt{};
		for (int i{}; i < N; i++)
		{
			ll bitmask{};
			cin >> str;
			for (const char &C : str)
			{
				int idx = C - 97; // lowercase letters
				Flip_ith_bit(bitmask, idx);
			}
			cnt += mp[bitmask]; // The possibility of XORing with 0
			for (int i{}; i < 26; i++)
			{
				if (mp.find(bitmask ^ (1LL << i)) != mp.end())
					cnt += mp[bitmask ^ (1LL << i)]; // XORing with another possible string having this ith bit set
			}
			mp[bitmask]++;
		}
		cout << cnt << endl;
	}
	return 0;
}