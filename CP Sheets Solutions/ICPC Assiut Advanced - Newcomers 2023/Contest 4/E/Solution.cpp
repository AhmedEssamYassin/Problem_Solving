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
#endif // !ONLINE_JUDGE

	int N;
	cin >> N;
	/*
	ONLY Uppercase English Letters
	Note: if you reach to the last letter ′Z′ start from the first letter 'A' again to complete the special triangle.

	Starting at i = 1
	- Number of lines = N

	- Number of spaces on each line is (N - 1), (N - 2), ... (0)
	  Which is an arithmetic sequence whose general term is: G.T = (N - i)

	- Number of characters to be printed on each line is 1, 3, 5, 7 ...
	  which is an arithmetic sequence whose general term: G.T = (2 * i - 1)
	*/
	for (int i{1}; i <= N; i++)
	{
		int Character{-1}; // In order to make (++Character) be 0 at the very first character to print

		cout << string(N - i, ' '); // Printing (N - i) spaces

		for (int j = 1; j <= 2 * i - 1; j++)
			cout << char((++Character %= 26) + 65);
		// (Character %= 26) returns the value to 0 every 26 characters printed
		cout << endl;
	}

	return 0;
}