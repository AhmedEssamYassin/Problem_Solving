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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		int K;
		string Input;
		cin >> N >> K;
		cin >> Input;
		/*
		if there is at least one letter 'a', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
		if there is at least one letter 'b', remove the leftmost occurrence and stop the algorithm, otherwise go to next item;
		.
		.
		.
		remove the leftmost occurrence of the letter 'z' and stop the algorithm.
		-----------------------------------------+-----------------------------------------+-----------------------------------------
		If K = N exit the program.(Remove ALL characters)
		Otherwise, count the number of occurrences of each letter i from 0 to 25 (Frequency array)
		Let it be arr[i]
		Now, find the (alphabetically) smallest letter that will be EXISTING in the resulting string. It can be done as follows:

		Iterate over all i from 0 to 25, and if arr[i] <= K (means it will be totally removed) then subtract it from k,
		otherwise, char(i + 97) will be the smallest letter that will be EXISTING in the resulting string.
		But we (possibly) need to remove some number of its leftmost occurrences.

		It is obvious that letters smaller than (preceding) char(i + 97) will NOT appear in the resulting string. (They ALL have been removed if existed)
		Also, the (remainder of K) leftmost occurrences of letter char(i + 97) will be removed.
		Now, let's iterate over all letters in string Input from left to right and construct the resulting string Res
		- If the current character of Input (let it be Input[j]) is smaller than char(i + 97), then do NOTHING. (It's NOT in the resulting string)
		- If Input[j] is greater than char(i + 97), then add it to Res.
		- Otherwise Input[j] will be the char(i + 97) itself, then:
		  If (remainder of K) > 0, i.e., this leftmost occurrence should be removed, then decrease K by one
		  otherwise, (ALL K operations are done), add Input[j] to Res

		The time complexity is O(n) (Traversal of the whole string Input)
		*/

		if (K == N)
			return 0; // It's Allowed to print NOTHING

		int arr[26] = {0}; // A frequency array for lower case latin characters
		for (const char &C : Input)
			arr[C - 97]++;

		string Res = ""; // To store the result
		int pos{25};
		for (int i{}; i < 26; i++)
		{
			if (arr[i] < K)
				K -= arr[i];
			else
			{
				pos = i; // The smallest character to exist in the resulting string
				break;
			}
		}

		int Remainder_of_K = K;
		for (const char &C : Input)
		{
			int cur = C - 'a'; // Current character
			if (cur > pos || (cur == pos && Remainder_of_K == 0))
				// If the current character is after the character at pos
				// Or if the current character is the one at pos but its Leftmost occurrences have been ALL deleted (ALL K operations are done)
				Res += C;

			else if (cur == pos) // If the current character is the character at pos itself and the K operations are NOT yet done
				Remainder_of_K--;
		}

		cout << Res;
	}
	return 0;
}
