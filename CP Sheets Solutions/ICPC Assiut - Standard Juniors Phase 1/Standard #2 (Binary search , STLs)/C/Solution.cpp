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

	int N, Q;
	cin >> N >> Q;

	string Input;
	cin >> Input;

	string Query;
	int X;
	while (Q--)
	{
		cin >> Query >> X;
		if (Query == "prev_permutation")
		{
			while (X--)
				prev_permutation(Input.begin(), Input.end());
			cout << Input << endl;
		}

		else if (Query == "next_permutation")
		{
			while (X--)
				next_permutation(Input.begin(), Input.end());
			cout << Input << endl;
		}
	}

	return 0;
}