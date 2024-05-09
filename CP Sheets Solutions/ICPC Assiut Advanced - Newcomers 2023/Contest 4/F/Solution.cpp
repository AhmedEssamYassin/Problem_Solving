#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Team
{
	string Name;
	int Number_of_Qs;
	int Total_time;
};
bool Predicate_function(const Team &T1, const Team &T2)
{
	// If there is a tie (Same number of questions is solved), then the team with less penalty (Total time) comes first
	if (T1.Number_of_Qs == T2.Number_of_Qs)
		return (T1.Total_time < T2.Total_time);
	else // The team who solves greater number of questions comes first
		return (T1.Number_of_Qs > T2.Number_of_Qs);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<Team> Teams(N);
		for (int i{}; i < N; i++)
			cin >> Teams[i].Name >> Teams[i].Number_of_Qs >> Teams[i].Total_time;

		sort(Teams.begin(), Teams.end(), Predicate_function);
		cout << Teams.front().Name << endl;
	}

	return 0;
}