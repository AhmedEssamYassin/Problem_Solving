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
	/*
	Given two strings S1 and S2, find the length of their longest uncommon subsequence,
	which is the longest string that is a subsequence of one of them and not a subsequence of the other.

	A subsequence of some string is a sequence of characters that appears in the same order in the string,
	The appearances don't have to be consecutive, for example, strings "ac", "bc", "abc" and "a" are subsequences of string "abc"
	while strings "abbc" and "acb" are not.
	The empty string is a subsequence of any string.
	Any string is a subsequence of itself.
	---------------------------------------------+---------------------------------------------+--------------------------------------
	If we analyze the problem carefully, it would seem much easier than it looks. All the three possible cases are as described below:

	1. If both the strings are identical, for example: “ac” and “ac”
	it is obvious that NO subsequence will be uncommon.

	2. If length(S1) = length(S2) and S1 != S2, for example: “abcdef” and “defghi”,
	out of these two strings one string will NEVER be a subsequence of other string
	Hence, return length(S1) or length(S2).

	3. If length(S1) > length(S2), for example: “abcdabcd” and “abcabc”
	in this case we can consider bigger string as a required subsequence because bigger string CANNOT be a subsequence of the smaller string.
	Hence, return max(length(S1), length(S2))
	*/
	string S1, S2;
	cin >> S1 >> S2;
	if (S1 == S2)
		cout << -1;
	else
		cout << max(S1.length(), S2.length());

	return 0;
}