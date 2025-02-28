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
		char coin_1, coin_2, op;
		int arr[3] = {0}; // The 3 characters A,B and C respectively
		// A is denoted as 0, B is denoted as 1 and C is denoted as 2

		/*
		Let's Assume initially that: A=B=C=0
		For each line if A > B for example, we should increment the value of A by 1 So that A becomes greater than B
		and if A < B for example, we should increment the value of B by 1 so that A becomes smaller than B
		After the results of all the weightings, values should belong to {0, 1, 2}, uniquely, So that the 3 coins can be sorted in an increasing order
		*/
		for (int i{}; i < 3; i++)
		{
			cin >> coin_1 >> op >> coin_2;
			if (op == '>')
				arr[coin_1 - 'A']++;
			else
				arr[coin_2 - 'A']++;
			;
		}
		// if any two characters have the same value, then it's Impossible because "No two coins are equal"
		if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
			return cout << "Impossible", 0;

		// A is denoted as 0, B is denoted as 1 and C is denoted as 2
		/*
				0	1	2
				A	B	C
				---------
	Initially:	0	0	0
		A > B	1	0	0
		B > C	1	1	0
		C < A	2	1	0
		*/
		for (int i{}; i < 3; i++) // To make the order of A,B and C,i.e. 0 MUST be before 1 and 1 MUST be before 2
		{
			for (int j{}; j < 3; j++) // A subscript to Traverse the values of A,B and C in arr
			{
				if (i == arr[j])
					cout << char(j + 'A');
			}
		}
	}
	return 0;
}
