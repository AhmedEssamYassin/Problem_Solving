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

	int Q;
	cin >> Q;

	deque<int> deq;

	string Query;
	int X;
	while (Q--)
	{
		cin >> Query;
		if (Query == "push_back")
		{
			cin >> X;
			deq.push_back(X);
		}

		else if (Query == "push_front")
		{
			cin >> X;
			deq.push_front(X);
		}

		else if (Query == "pop_back")
			deq.pop_back();

		else if (Query == "pop_front")
			deq.pop_front();

		else if (Query == "front")
		{
			if (!deq.empty())
				cout << deq.front() << endl;
		}
		else if (Query == "back")
		{
			if (!deq.empty())
				cout << deq.back() << endl;
		}

		else if (Query == "print")
		{
			cin >> X; // 1-based

			X--; // To make it 0-based
			cout << deq.at(X) << endl;
		}
	}

	return 0;
}