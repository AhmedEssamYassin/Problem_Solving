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
	int L, R, pos;
	char C;
	while (Q--)
	{
		cin >> Query;
		if (Query == "front")
			cout << Input.front() << endl;

		else if (Query == "back")
			cout << Input.back() << endl;

		else if (Query == "push_back")
		{
			cin >> C;
			Input.push_back(C);
		}

		else if (Query == "pop_back")
			Input.pop_back();

		else if (Query == "print")
		{
			cin >> pos; // 1-based
			cout << Input[pos - 1] << endl;
		}

		else if (Query == "substr")
		{
			cin >> L >> R; // 1-based

			L > R ? swap(L, R) : void(NULL); // To make L <= R

			L--, R--; // To make L and R be 0-based
			// Input.substr(pos, len)
			cout << Input.substr(L, R - L + 1) << endl;
		}

		else if (Query == "sort")
		{
			cin >> L >> R; // 1-based

			L > R ? swap(L, R) : void(NULL); // To make L <= R

			L--, R--; // To make L and R be 0-based
			// Input.sort(first, last)
			sort(Input.begin() + L, Input.begin() + R + 1);
		}

		else if (Query == "reverse")
		{
			cin >> L >> R; // 1-based

			L > R ? swap(L, R) : void(NULL); // To make L <= R

			L--, R--; // To make L and R be 0-based
			// Input.reverse(first, last)
			reverse(Input.begin() + L, Input.begin() + R + 1);
		}
	}

	return 0;
}