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
	You will be given an integer N
	what is the number of positive integers less than or equal to N that aren't divisible by 7

	The integer division (X / Y) computes how many multiples of Y do Exist from 1 to X
	Example:
	(23 / 5) = 4
	That means there are 4 multiples of 5 from 1 to 23 which are {5, 10, 15, 20}

	The number of positive integers <= N that aren't divisible by 7 = N - the number of positive integers <= N that are divisible by 7
	So the answer to this question is obviously: N -  (N / 7)
	*/
	ll N;
	cin >> N;
	cout << N - N / 7;

	return 0;
}