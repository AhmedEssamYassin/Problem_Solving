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

	int Length;
	string Initial, Target;
	cin >> Length >> Initial >> Target;
	/*
	Initial and Target statements are just strings of zeros and ones.
	At each step, He can take any substring of the Initial statement and negate it — replace each zero with one, and each one with zero.
	He would like to leave NO trace of his actions, so he wants to minimize the number of steps in turning the initial statement to the target.

	To minimize the number of steps, we need to choose the Longest Mis-Matching Substring to negate at each step.
	*/
	// 1010101
	// 0011100

	int Steps{};
	int LMMS{}; // Longest MisMatching Substring
	for (int i{}; i < Length; i++)
	{
		if (Initial[i] != Target[i]) // If they mismatch, expand the length of the LMMS
			LMMS++;
		else // If they match, i.e. the LMMS (if exists) ended and we need to negate it (make a step if a LMMS exists)
		{
			Steps += (LMMS > 0);
			LMMS = 0; // Resets the length to 0 to start handling a new LMMS
		}
	}
	Steps += (LMMS > 0); // Handles the case where the last character mismatches
	cout << Steps;

	return 0;
}