#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	For any i and j, (a[i] ^ a[j]) < 4 iff the two numbers are the same in all bits except the first two bits
	This is because if they have a mismatch in any other bit, their XOR will include this bit, making its value >= 4

	This means that we can group the numbers by removing the last two bits and putting equal numbers into the same group.
	In each group, we can order the numbers freely (since we can swap any two of them)
	and of course it's optimal to sort the numbers in each group in ascending order.
	*/
	int t = 1;
	ll N, x;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N);
		map<ll, priority_queue<ll, vector<ll>, greater<>>> BitGroups;
		for (int i{}; i < N; i++)
		{
			cin >> a[i];
			BitGroups[a[i] >> 2].push(a[i]);
		}
		for (int i{}; i < N; i++)
		{
			auto &curGroup = BitGroups[a[i] >> 2];
			cout << curGroup.top() << " ", curGroup.pop();
		}
		cout << endl;
	}
	return 0;
}