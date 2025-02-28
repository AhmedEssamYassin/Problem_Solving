#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int a[1000000]; // To store input numbers
int b[10];		// To store the input numbers after converting
// Index is the input number in binary bits
// Value is the input number in decimal representation

int Convert(int x)
{
	/*
	Converts the decimal number to binary bits where:
	- ALL bits corresponding to 0's are ALSO 0's
	- ALL bits corresponding to NON-zeros are 1's
	Example:
	12301520
	11101110 which is 238
	*/
	int res = 0;
	int k = 0;
	while (x)
	{
		if (x % 10 != 0) // If the last digit is NOT 0
			res |= (1 << k);

		k++;

		x /= 10; // Removes the last digit
	}
	return res;
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
	You should pick the largest subset that for every two elements, A and B, there should be at least one zero in A%10 and B%10,
	at least one zero in A/10%10 and B/10%10, and at least one zero in A/100%10 and B/100%10.
	Example:
	071 which is 71
	100
	- CAN be paired because one of every two corresponding digits is 0
	while
	16
	10
	- CANNOT be paired because the digit corresponding to 1 is 1 (NOT 0)

	If there is ONLY ONE number, it will be chosen as the optimal subset because it has no pair that contradict the condition i.e. the condition STILL HOLDS
	--------------------------------------------------------------------------------------------------------------------------------------------------------
	The idea is to convert all input numbers to  binary bits where:
	- Set bits (1's) are NON-zero numbers
	- Unset bits (0's) are Zero numbers
	For every pair (A,B) on form of binary bits, if ((A&B) == 0) that means they are a VALID pair
	because it means that every two corresponding bits are (0,1), (1,0) or (0,0)
	which means that every two corresponding digits in the input numbers had at least one zero which is required to satisfy the condition.
	Example:
	11100100010
	00011011000
	----& op---
	00000000000 = 0
	This pair is VALID

	-But which numbers should be chosen as the elements of the subset?
	The subset will totally change based on the elements chosen!
	because they will determine which numbers to accept or reject from ALL other numbers of the whole set.
	We need to try every possible subset and take the subset with maximum length!

	Note the following:
	-------------------
	One byte = collection of 8 bits
	e.g. 0 1 0 1 1 0 1 0
	One byte can store one character, e.g. 'A' or 'x' or '$'
	Mathematically: N bits yields 2^N patterns (because every bit has two choices, either 1 or 0)
	So,
	1 Byte ( = 8 bits ) can make 256 different patterns
	How to use the 256 patterns?
	How to store a number in a byte?
	Start with 0, go up, one pattern per number, until run out of patterns
	0, 1, 2, 3, 4, 5, ... 254, 255
	One byte can hold a number between 0 and 255
	i.e. with 256 different patterns, we can store a number in the range [0, 256]

	NOTE:
	MSB
	|
	100100101
			|
			LSB
	*/
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		memset(b, -1, sizeof(b)); // Initializes all the array b to {-1}
		int k;
		cin >> k;
		for (int i{}; i < k; i++)
		{
			cin >> a[i];		   // Example: 100 10 1 0
			int x = Convert(a[i]); // 100 10 1 0 when converted to int : 4 2 1 0

			if (b[x] == -1)	 // If NOT calculated
				b[x] = a[i]; // b[4] = 100, b[2] = 10, b[1] = 1, b[0] = 0
		}

		vector<int> res;			// To store the desired subset
		for (int i{}; i < 256; i++) // To traverse all possible patterns
		{
			/*
			Each time, we check if ((i & (1<<j)) > 0) with every j in range [0,7]
			i.e. we check that 		(i & {1, 2, 4, 8, 16, 32, 64, 128} > 0 )
			which, in base 2, is 	(i & {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000} > 0 )
			-----------------
				i	: State
			-----------------
			0 (0)	: Excludes ALL numbers because (0 & ( 1 << j)) = 0 whatever the value of j is
			1 (1)	: Includes ONLY j = 0 because (1 & (1 << 0)) = 1
			2 (10)	: Includes ONLY j = 1 because (2 & (1 << 1)) = 2 (NOT 0)
			3 (11)	: Includes ONLY j = 0 and j = 1 because (3 & (1 << 0)) = 1 and (3 & (1 << 1)) = 2
			.
			.
			.
			255 (11111111) : Includes ALL j's because (255 & (1 << j)) != 0 for ANY j
			*/
			vector<int> V;
			for (int j{}; j < 8; j++)
			{
				if (((i >> j) & 1) > 0 && b[j] != -1)
					V.push_back(j);
			}

			int n = V.size();

			// Checks if it's a VALID subset
			bool ok = true;
			for (int j{}; j < n; j++)
				for (int k = j + 1; k < n; k++)
				{

					if ((V[j] & V[k]) != 0)
						ok = false;
				}

			if (ok && res.size() < V.size())
				res = V;
		}

		cout << res.size() << endl;
		for (int i{}; i < res.size(); i++)
			cout << b[res[i]] << ' ';
		cout << endl;
	}
	return 0;
}
