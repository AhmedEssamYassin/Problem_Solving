#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Some useful calculations on bits:
---------------------------------
(1 << i) is a number with ONLY the i-th bit set

~(i << i) is a number with all bits set and ONLY the i-th bit cleared

(N - 1) flips all bits after the rightmost set bit of N, including the rightmost set bit
Assume N = 00110100
00110100
-
00000001
=
00110011
Explanation:
(0 - 1) is NOT possible, so we should borrow a 1, which is the rightmost set bit, here it's 4 so it flips to 0 and 4 - 1 is 3 which is 11 in binary
and all other bits will be either (1 - 0) or (0 - 0) so they remain without any change

(N + 1) flips all bits after the rightmost cleared bit of N, including the rightmost cleared bit
Assume N = 0011011111
001101011111
+
000000000001
=
001101100000
Explanation:
(1 + 1) is 2 which is in binary 10 i.e., 0 with a carry = 1.
This carry will still give (10) base 2, if added with any set bit and ONLY gives 1 when added with a cleared bit (which will be the rightmost cleared bit)
and all other bits will be either (1 + 0) or (0 + 0) so they remain without any change

1. set the i-th bit of the number N: (N | (1 << i))
2. flip the i-th bit of the number N: (N ^ (1 << i))
3. clear the i-th bit of the number N: (N & ~(1 << i))
4. check if the i-th bit is set: bool(N & (1 << i))
5. clear the rightmost set bit: (N & (N - 1))
6. Brian Kernighan's algorithm: A way to count set bits using the previous fact
it simply clears the rightmost set bit and counts it iteratively until the number is 0
7. clear ALL trailing 1's: (N & (N + 1))
8. set the last cleared bit: (N | (N + 1))
9. get the rightmost set bit: (N & (-N)) or (N & ~(N - 1))
10. Clear all bits from LSB to ith bit:         mask = ~((1 << i+1 ) - 1); x &= mask;
11. Clearing all bits from MSB to i-th bit:     mask = (1 << i) - 1; x &= mask;
*/

// Bits indices are traversed from right to left

template <typename T>
void Set_ith_bit(T &N, uint16_t i) // 0-based
{
	// 11100101(0)11 | 00000000(1)00 = 11100101(1)11
	N = (N | (T(1) << i));
}

template <typename T>
void Flip_ith_bit(T &N, uint16_t i) // 0-based
{
	// 111001010(1)1 ^ 000000000(1)0 = 111001010(0)1
	N = (N ^ (T(1) << i));
}

template <typename T>
void Clear_ith_bit(T &N, uint16_t i) // 0-based
{
	// 1110010(1)011 & 1111111(0)111 = 1110010(0)011
	N = (N & ~(T(1) << i));
}

template <typename T>
bool Check_ith_bit_set(T &N, uint16_t i) // 0-based
{
	// 11100101(0)11 & 00000000(1)00 = 00000000000 (it's a cleared bit)
	return (N & (T(1) << i));
	// return ((N >> i) & 1) == 1; // 110100, i = 4  -->  110 & 1 = 0
}

template <typename T>
void Clear_rightmost_set_bit(T &N)
{
	// 11100101(1)00 & 11100101(0)11 = 11100101(0)00
	N = (N & (N - 1));
}

template <typename T>
int Count_set_bits(T N)
{
	int cnt{};

	while (N)
	{
		Clear_rightmost_set_bit(N);
		cnt++;
	}
	return cnt;
}

template <typename T>
void Clear_all_trailing_ones(T &N)
{
	// 111001010(11) & 111001011(00) = 111001010(00)
	N = (N & (N + 1));
}

template <typename T>
void Set_last_cleared_bit(T &N)
{
	// 11100101(0)11 | 11100101(1)00 = 11100101(1)11
	N = (N | (N + 1));
}

template <typename T>
int Get_rightmost_set_bit_number(const T &N)
{
	// 11100101(1)00 & ~(11100101(0)11) = 11100101(1)00 & 00011010(1)00 = 00000000(1)00
	return (N & ~(N - 1));
	// return (N & (-N));
	// return log2(N & (N-1)) + 1; // gives the index of the rightmost_set_bit (0-indexed)
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int N, Q, X;
	cin >> Q >> N;

	int Query;
	while (Q--)
	{
		cin >> Query;
		switch (Query)
		{
		case 1:
			cin >> X;
			N |= X;
			break;
		case 2:
			cin >> X;
			N &= X;
			break;
		case 3:
			cin >> X;
			N ^= X;
			break;
		case 4:
			N = ~N;
			break;
		}
		cout << N << endl;
	}
	return 0;
}