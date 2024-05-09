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
#endif // !ONLINE_JUDGE

	/*
	You are given an integer number N and array A of N Characters (consisting of digits ,uppercase and lowercase English letters),
	in order to unlock the laptop,
	You must answer by the number of sub arrays with size AT LEAST 3 (size >= 3) that you can reorder it to become a palindrome.

	1- A sub array of array is an array composed from a contiguous block of the original array's elements.
	   In other words A sub-array A[i−j], where (1 <= i <= j <= N), is a sequence of integers A[i], A[i+1], ..., A[j]

	2- An array is called palindrome if it reads the same backward and forward.
	-----------------------------------------------------------------------------------------------------------------------------
	For a string to have the capability of being reordered to become a palindrome:
	1. If length is EVEN: ALL characters MUST have EVEN occurrence
	2. If length is ODD : ALL characters MUST have EVEN occurrence EXCEPT the middle character should have ODD occurrence

	Let's make a Bitmask of 128 bits to represent Parity of the occurrence of each character in each substring (of Sub array)
	Let the OFF state of a bit (a cleared bit) represent the EVEN occurrence
	Let the ON state of a bit (a set bit) represent the ODD occurrence
	As ODD parity and EVEN parity alternate with each increment
	i.e., (ODD + 1 = EVEN) and (EVEN + 1 = ODD)
	A bit representing the occurrence of a character needs to be flipped with each occurrence
	At the end:
	1. If length is EVEN:
	ALL characters MUST have EVEN occurrence, i.e., the Bitmask = 0
	2. If length is ODD :
	ALL characters MUST have EVEN occurrence EXCEPT the middle character should have ODD occurrence, i.e., Bitmask should has a single bit ON (set)

	That Bitmask CANNOT be an int or even long long int because the string will contain lowercase and uppercase characters and also digits
	and the ASCII of these characters will definitely exceed 64 bits
	We can make either:
	- A bitset<128> Bitmask
	- __int128_t Bitmask
	*/
	short int N;
	cin >> N;
	string Input;
	cin >> Input;

	int cnt{};
	for (int i{}; i < N; i++)
	{
		for (int j{i}; j < N; j++)
		{
			// bitset<123> Bitmask;
			__int128_t Bitmask = 0;
			for (int k{i}; k <= j; k++)
				// Bitmask.flip(Input[k] + 1); // Flip that bit representing the character
				Flip_ith_bit(Bitmask, Input[k] + 1);

			short int len = j - i + 1;
			if (len >= 3)
			{
				if (((len & 1) && __has_single_bit(Bitmask)) || (len % 2 == 0 && Bitmask == 0))
					cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}