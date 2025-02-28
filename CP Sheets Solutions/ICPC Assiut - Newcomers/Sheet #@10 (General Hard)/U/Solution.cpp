#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isSubsequence(const string &S, const string &T)
{
	int N = S.length(), M = T.length();
	int i = 0, j = 0;
	while (i < N && j < M)
	{
		if (S[i] == T[j])
			i++;
		j++;
	}
	// If i reaches the length of S,that mean we found all characters of S in T, in ORDER . So, S is a subsequence of T, else it's NOT.
	// S = "abc"		T = "bxyzahgc" 	:	S is NOT a subsequence of T
	return (i == N);
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
	If the answer exists, then each element of string S matches with some element of string T. Thereby string S MUST be a subsequence of string T.
	i.e. ALL the characters in string S MUST appear in the same order they appears in string T

	Let Freq_str(C) equal to the number of occurrences of the letter C in the string str. Then for any letter C  The following condition MUST hold:
	Freq_P(C) >= Freq_T(C) - Freq_S(C)
	That means that the number of occurrences of the letter C in the string P can compensate the difference (if exists) between T and S

	So, the answer to the query is YES if both the following conditions hold:

	1. String S is a subsequence of string T: ALL the characters in string S MUST appear in the same order they appears in string T

	2. Freq_P(C) >= Freq_T(C) - Freq_S(C) for any Latin latter C

	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		string S, T, P;
		cin >> S >> T >> P;
		if (S.length() > T.length()) // We CANNOT remove any characters so S will never become equal to T
		{
			cout << "NO\n";
			continue;
		}

		if (S.length() == T.length() && S != T) // They are the same length, so we CANNOT insert any characters so S will never become equal to T
		{
			cout << "NO\n";
			continue;
		}

		if (!(isSubsequence(S, T))) // String S MUST be a subsequence of string T
		{
			cout << "NO\n";
			continue;
		}

		map<char, int> Freq_S, Freq_T, Freq_P; // To store the frequency of each character in strings S,T and P
		for (char C : S)
			Freq_S[C]++;
		for (char C : T)
			Freq_T[C]++;
		for (char C : P)
			Freq_P[C]++;

		bool flag = true;
		/*
		-We MUST traverse the characters of string T (NOT S or P)
		Because T is the string containing ALL mandatory (required) characters to exist in S,
		while S can contain less characters than the required (CANNOT contain more characters than required because if so, it wouldn't have been a subsequence of T,
		i.e. we wouldn't reach this line of code because of 'continue')
		also, P can contain more or less characters than the required
		*/
		for (auto it : Freq_T)
		{
			if (Freq_T[it.first] != Freq_S[it.first])
				if (Freq_P[it.first] < (Freq_T[it.first] - Freq_S[it.first]))
				{
					flag = false;
					break;
				}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
