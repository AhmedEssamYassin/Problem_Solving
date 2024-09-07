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

	int N, K;
	string Input;
	cin >> N >> K >> Input;

	// Find the maximum number of distinct letters you can obtain by taking a substring of length K
	// Fixed-size sliding window
	deque<char> deq;
	int arr[26] = {0}; // A frequency array for characters

	int Max_distinct_characters = 0;
	int len{};
	for (const char &C : Input)
	{
		deq.push_back(C); // Expanding the window (pushing a character to the right)

		arr[C - 97]++; // Counting frequency

		if (arr[C - 97] == 1) // If it's a distinct character, i.e., If it's the first time to appear, count it
			len++;

		if (deq.size() == K) // A window of size K (A substring of length K)
		{
			Max_distinct_characters = max(Max_distinct_characters, len);
			if (arr[deq.front() - 97] == 1) // If the character occurs ONLY once (A distinct character)
				len--;

			arr[deq.front() - 97]--; // reduce its frequency by 1 because it's been removed

			// Deleting the first character in order to push a new character to acquire a new window of length K
			deq.pop_front();
		}
	}

	cout << Max_distinct_characters;
	return 0;
}