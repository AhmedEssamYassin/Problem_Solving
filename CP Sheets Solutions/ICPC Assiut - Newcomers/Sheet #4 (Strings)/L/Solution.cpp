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
	int N;
	// cin >> t;
	while (t--)
	{
		int N, Q, L, R;
		string S, query;
		char C;
		cin >> N >> Q;
		cin >> S;
		while (Q--)
		{
			cin >> query;

			if (query == "pop_back")
				S.pop_back();

			else if (query == "front")
				cout << S.front() << endl;

			else if (query == "back")
				cout << S.back() << endl;

			else if (query == "sort")
			{
				cin >> L >> R;
				if (L > R)
					swap(L, R); // To make sure L <= R
				sort(S.begin() + L - 1, S.begin() + R);
			}
			else if (query == "reverse")
			{
				cin >> L >> R;
				if (L > R)
					swap(L, R); // To make sure L <= R
				reverse(S.begin() + L - 1, S.begin() + R);
			}
			else if (query == "print")
			{
				cin >> L;
				cout << S.at(L - 1) << endl;
			}
			else if (query == "substr")
			{
				cin >> L >> R;
				if (L > R)
					swap(L, R); // To make sure L <= R
				cout << S.substr(L - 1, R - L + 1) << endl;
			}
			else if (query == "push_back")
			{
				cin >> C;
				S.push_back(C);
			}
		}
	}
	return 0;
}