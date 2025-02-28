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
		cin >> N;
		vector<int> arr(N);
		for (int i{}; i < N; i++)
			cin >> arr[i];
		/*
		Since we can swap any two neighboring numbers as many times as we want
		this means we can shuffle the array in any way
		1					YES		It's distinct
		1 1					NO		Needs another number in between
		1 1 1				NO		Needs other 2 numbers in between
		1 1 1 1				NO		Needs other 3 numbers in between
		Conclusion:
		if a number is repeated C times, it needs AT LEAST (C - 1) other numbers to be inserted between each two
		to have an array where each two numbers are distinct
		Approach:
		1. Traverse the array and get the number of occurrences of all numbers (using a map)
		2. Traverse the map and check that for each frequency C of a number of the array, it's fulfilled that (C - 1 <= N - C) --> (C + C - 1 <= N) --> (2C - 1 <= N)
		AT LEAST means <= (N - C) is number of other numbers
		From all mentioned above, we deduce that if (2C - 1 > N) for any number, the answer is "NO".
		Otherwise, if all numbers' frequencies fulfil the condition that (2C - 1 <= N), the answer is "YES".
		*/
		map<int, int> mp;
		for (int i{}; i < N; i++)
			mp[arr[i]]++;
		for (auto &[number, occ] : mp)
		{
			if (2 * occ - 1 > N)
				return cout << "NO", 0;
		}
		cout << "YES";
	}
	return 0;
}
