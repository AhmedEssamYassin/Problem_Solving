#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> Lucky_numbers;
void Generate_Lucky_Numbers(ll N)
{
	/*
	Starting from 0, We can build ALL lucky numbers
	At each digit, we have ONLY 2 choices:
	1. Make it 4
	2. Make it 7
	because lucky numbers contain ONLY 4's and 7's
	*/

	// if (N > 1e18) // It's efficient until 10^18
	if (N > 1e5)
		return;
	if (N) // If it's NOT 0, then it's A lucky number
		Lucky_numbers.push_back(N);

	Generate_Lucky_Numbers(N * 10 + 4); // Make it 4
	Generate_Lucky_Numbers(N * 10 + 7); // Make it 7
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	Generate_Lucky_Numbers(0); // It's extremely fast, It's O(2^18)

	// It generates Lucky numbers UNSORTED, so we need to sort them first
	sort(Lucky_numbers.begin(), Lucky_numbers.end());

	int A, B;
	cin >> A >> B;
	bool No_Lucky_Numbers = true;
	for (const ll &number : Lucky_numbers)
	{
		if (number >= A and number <= B) // In interval [A, B]
		{
			cout << number << " ";
			No_Lucky_Numbers = false;
		}
	}
	if (No_Lucky_Numbers)
		cout << -1;
	return 0;
}