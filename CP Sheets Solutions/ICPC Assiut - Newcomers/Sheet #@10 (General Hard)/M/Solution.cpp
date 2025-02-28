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
		string Msg;
		int k;
		cin >> Msg >> k;
		int snowflakes{}, candy_cones{};
		for (const char &C : Msg)
		{
			if (C == '*')
				snowflakes++;
			else if (C == '?')
				candy_cones++;
		}
		/*
		If the string in the postcard does not contain any snowflakes or candy cones, k must be equal to the length of the string.
		Because the only string encoded by such message is the string itself, and in this case if k is not equal to the length of the string,
		the answer is «Impossible».
		*/

		// Since snowflakes and candy_cones are greater than or equal to 0 as they represent the frequency of '*' and '?',
		// if(snowflakes + candy_cones == 0), They both MUST be 0
		if (snowflakes + candy_cones == 0 and Msg.length() != k)
			return cout << "Impossible", 0;
		//--------------------------------------------------------------------------------------------------------------------------------------
		/*
		Let's call the characters of the message mandatory if they are not followed by snowflakes or candy cones.
		They are mandatory because we CANNOT delete any of them.
		So assuming we deleted all other NON-mandatory characters:
		Clearly k should be at least equal the number of mandatory characters, i.e. (k >= number of mandatory characters)
		Otherwise, (k < number of mandatory characters), the answer is «Impossible», because we CANNOT delete more characters to reach k
		*/

		// To delete all NON-mandatory characters, we delete all symbols ('*' and '?') and their preceding character
		if (Msg.length() - 2 * (snowflakes + candy_cones) > k)
			return cout << "Impossible", 0;
		//--------------------------------------------------------------------------------------------------------------------------------------
		/*
		In case there is a snowflake (*) in the message:
		we can repeat the preceding character enough times to get the length k , and remove the rest of NON-mandatory characters(and symbols).
		*/
		if (snowflakes != 0)
		{
			int pos = Msg.find('*'); // To find the first '*'

			Msg.erase(Msg.begin() + pos);
			snowflakes--; // Decrement the frequency of '*' by 1 because we deleted it
			while (Msg.length() - 2 * (snowflakes + candy_cones) < k)
				Msg.insert(Msg.begin() + pos, Msg[pos - 1]); // Or insert any arbitrary character

			// Do we have to remove the preceeding character of the first '*' ?
			if (Msg.length() - 2 * (snowflakes + candy_cones) > k)
				Msg.erase(Msg.begin() + pos - 1);

			// Delete all NON-mandatory characters and symbols
			for (int i{}; i < Msg.length(); i++)
			{
				if (Msg[i] == '?' || Msg[i] == '*') // ABSCSAS?SD*
				{
					Msg.erase(Msg.begin() + i);
					Msg.erase(Msg.begin() + i - 1);
					i -= 2; // because we erased two characters, now the subscript i is ahead by 2, that's why we subtract 2
				}
			}
		}
		/*
		If case there are no snowflakes, but only candy cones:
		we should use the characters followed by candy cones until we get the desired length k.
		In case we don't have enough, the answer is «Impossible».
		*/
		else
		{
			if (Msg.length() - candy_cones < k) // if we leave all preceding characters of '?' and still not of length k
				return cout << "Impossible", 0;

			for (int i{}; i < Msg.length(); i++)
			{
				if (Msg[i] == '?')
				{
					Msg.erase(Msg.begin() + i);
					candy_cones--;							 // Decrement the frequency of '?' by 1 because we deleted it
					if (Msg.length() - 1 - candy_cones >= k) // Can we delete the preceding character?
						Msg.erase(Msg.begin() + i - 1), i--; // because we erased 1 character, now the subscript i is ahead by 1, that's why we subtract 1
				}
			}
		}
		cout << Msg;
	}
	return 0;
}
