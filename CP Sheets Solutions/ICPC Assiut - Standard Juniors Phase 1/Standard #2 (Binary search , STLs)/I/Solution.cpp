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

	int N, Q, X;
	cin >> N;
	vector<int> Prices(N);
	for (int i{}; i < N; i++)
		cin >> Prices[i]; // 3 10 8 6 11

	sort(Prices.begin(), Prices.end()); // To apply the upper_bound() function
	// 3 6 8 10 11

	/*
	- The number of shops where he will be able to buy a bottle of the drink on the i-th day.
	  i.e., The number of shops whose price is less than or equal to the number of coins he can spend on the i-th day.

	- We can get the number of elements that are less than or equal to X as follows:
	1. sort elements in an ascending order
	2. get the index of the first element which is greater than or equal to X using:
	   (lower_bound(first, last, X) - Vec.begin())

	The problem arises when there is one or more elements that are equal to X
	because they should be counted but this method would NOT count them!

	To solve this problem, we can either:
	- Use (upper_bound(first, last, X) - Vec.begin()) instead, because it will get the index of the first element which is greater than X
	  i.e., If there are one or more elements that are equal to X, they will be ALREADY counted!
	- Add the Occurrence of X to the calculation (lower_bound(first, last, X) - Vec.begin())
	*/

	map<int, int> Occurrence;
	for (const int &price : Prices)
		Occurrence[price]++;

	cin >> Q;
	while (Q--)
	{
		cin >> X;
		cout << (upper_bound(Prices.begin(), Prices.end(), X) - Prices.begin()) << endl;
		// Or
		// cout << (lower_bound(Prices.begin(), Prices.end(), X) - Prices.begin()) + Occurrence[X] << endl;
	}

	return 0;
}