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

	queue<int> Que;

	string Query;
	int X;
	while (Q--)
	{
		cin >> Query;
		if (Query == "push")
		{
			cin >> X;
			Que.push(X);
		}

		else if (Query == "pop")
			Que.pop();

		else if (Query == "front")
		{
			if (!Que.empty())
				cout << Que.front() << endl;
		}
		else if (Query == "back")
		{
			if (!Que.empty())
				cout << Que.back() << endl;
		}
	}

	return 0;
}