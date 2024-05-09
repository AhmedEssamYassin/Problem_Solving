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

	priority_queue<int> pr_que;

	string Query;
	int X;
	while (Q--)
	{
		cin >> Query;
		if (Query == "push")
		{
			cin >> X;
			pr_que.push(X);
		}

		else if (Query == "pop")
			pr_que.pop();

		else if (Query == "top")
			cout << pr_que.top() << endl;
	}

	return 0;
}