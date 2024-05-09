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
	cin >> Q >> N;

	int Query;
	while (Q--)
	{
		cin >> Query;
		switch (Query)
		{
		case 1:
			cin >> X;
			N |= X;
			break;
		case 2:
			cin >> X;
			N &= X;
			break;
		case 3:
			cin >> X;
			N ^= X;
			break;
		case 4:
			N = ~N;
			break;
		}
		cout << N << endl;
	}
	return 0;
}