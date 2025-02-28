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
	ll N;
	// cin >> t;
	while (t--)
	{
		string A, B;
		cin >> A >> B;
		// If the two strings are of different lengths, there is NO WAY they can be equal
		if (A.length() != B.length())
			return cout << "NO", 0;

		string diff = "";
		vector<pair<char, char>> Diff_Pairs;
		int cnt{};
		// Hussein MUST Make ONE move, in that move he will swap 2 characters
		// If the Two strings are initially the same, we must find AT LEAST two equal characters to swap without changing the state
		// This can be easier if we sort the string and search for AT LEAST two adjacent equal characters to swap without changing the state
		// If No such adjacent characters exist, the Answer would be "NO"
		if (A == B)
		{
			for (int i{1}; i < A.length(); i++)
			{
				sort(A.begin(), A.end());
				if (A[i] == A[i - 1])
					return cout << "YES", 0;
			}
			cout << "NO";
		}
		/*
		If the Two strings are not initially the same, There MUST be ONLY 2 differences. More or less differences will make it impossible to make the two strings equal
		The two differences would have a pattern, let's see:
		ahhedf
		   | |
		ahhfde
		The first different pair is P1 = {'e','f'} and the other pair is P2 = {'f','e'}
		So, P1.first MUST equal P2.second and P1.second MUST equal P2.first
		A further Notice: if the two pairs are pushed in a string "effe", it MUST be a PALINDROME
		*/
		else
		{
			for (int i{}; i < A.length(); i++)
			{
				if (A[i] != B[i])
					Diff_Pairs.push_back({A[i], B[i]}), cnt++;
			}
			if (cnt == 2 && (Diff_Pairs[0].first == Diff_Pairs[1].second && Diff_Pairs[0].second == Diff_Pairs[1].first))
				cout << "YES";
			else
				cout << "NO";
		}
	}
	return 0;
}
