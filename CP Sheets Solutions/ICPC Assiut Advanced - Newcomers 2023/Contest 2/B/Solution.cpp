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

	/*
	Given three integers N, A and B
	Determine how many numbers from 1 to N are divisible by (A+B)

	The integer division (X / Y) computes how many multiples of Y do Exist from 1 to X
	Example:
	(23 / 5) = 4
	That means there are 4 multiples of 5 from 1 to 23 which are {5, 10, 15, 20}
	So the answer to this question is obviously the integer division (N / (A + B))
	*/
	ll N, A, B;
	cin >> N >> A >> B;
	cout << N / (A + B);

	return 0;
}