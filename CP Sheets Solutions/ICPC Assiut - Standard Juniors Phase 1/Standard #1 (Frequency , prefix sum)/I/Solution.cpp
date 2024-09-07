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

	int N, Q, L, R, pos;
	cin >> N >> Q;
	vector<int> Vec(N);
	for (size_t i{}; i < N; i++)
		cin >> Vec[i];

	string Query;
	while (Q--)
	{
		cin >> Query;
		if (Query == "front")
			cout << Vec.front() << endl;

		else if (Query == "back")
			cout << Vec.back() << endl;

		else if (Query == "print")
		{
			cin >> pos; // 1-based

			pos--; // To make it 0-based
			cout << Vec[pos] << endl;
		}

		else if (Query == "push_back")
		{
			cin >> L;
			Vec.push_back(L);
		}

		else if (Query == "pop_back")
			Vec.pop_back();

		else if (Query == "sort")
		{
			cin >> L >> R; // 1-based

			L--, R--; // To make them 0-based
			sort(Vec.begin() + min(L, R), Vec.begin() + max(L, R) + 1);
		}

		else if (Query == "reverse")
		{
			cin >> L >> R; // 1-based

			L--, R--; // To make them 0-based
			reverse(Vec.begin() + min(L, R), Vec.begin() + max(L, R) + 1);
		}
	}
	return 0;
}