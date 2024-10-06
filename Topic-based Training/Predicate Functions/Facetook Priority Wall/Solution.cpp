#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool predicate_func(const pair<string, int> &P1, const pair<string, int> &P2)
{
	// {Name, priority}
	if (P1.second == P2.second)		// Same priority
		return P1.first < P2.first; // Lexicographical order

	return P1.second > P2.second; // Sort in descending order
}

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
	string myName, name1, name2, action;
	map<string, int> points = {{"posted", 15}, {"commented", 10}, {"likes", 5}};
	// cin >> t;
	while (t--)
	{
		cin >> myName;
		cin >> N;
		vector<pair<string, int>> prList;
		map<string, int> factor; // To maintain distinct names
		for (int i{}; i < N; i++)
		{
			cin >> name1;
			cin >> action;

			if (action == "posted" || action == "commented")
			{
				cin >> name2;
				cin >> name2;	  // Overwrites "on"
				name2.pop_back(); // removes 's'
				name2.pop_back(); // removes apostrophe
			}
			else // "likes"
			{
				cin >> name2;
				name2.pop_back(); // removes 's'
				name2.pop_back(); // removes apostrophe
			}
			// we need to parse the rest of the line
			cin.ignore(256, '\n');

			// Recording priority of MY FRIENDS (myName should be one of the two names to record priority)
			if (name1 == myName)
				factor[name2] += points[action];
			else
				factor[name1];
			if (name2 == myName)
				factor[name1] += points[action];
			else
				factor[name2];
		}
		for (auto &it : factor)
			prList.push_back({it.first, it.second});

		sort(prList.begin(), prList.end(), predicate_func);
		for (int i{}; i < prList.size(); i++)
			cout << prList[i].first << endl;
	}
	return 0;
}