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
	A string S is beautiful if there is NO common letter (at the same index) between the string and its reverse.

	Given a string S that consists of lowercase Latin letters, determine if it is possible to reorder the letters to make a beautiful string.

	1. If the string S consists of an ODD number of characters,
	it CANNOT be or made beautiful in any order because the MIDDLE character will always be common between that string and its reverse.

	2. Otherwise, if the string S consists of an EVEN number of characters,
	Each character MUST have a different counterpart in the reversed string
	So, if a character C occurs k times, there MUST be AT LEAST k different characters in the string S, other than that character C, to make it beautiful
	i.e. for each character C, this condition:
	(S.length() - Frequency[C] >= Frequency[C]) MUST hold
	*/
	string S;
	cin >> S;
	if (S.length() & 1) // If the string S consists of an ODD number of characters
		cout << "NO";
	else // If the string S consists of an EVEN number of characters
	{
		map<char, int> Frequency;
		for (char C : S)
			Frequency[C]++;

		for (auto it : Frequency)
		{
			if (S.length() - it.second < it.second)
				return cout << "NO", 0;
		}
		cout << "YES";
	}
	return 0;
}