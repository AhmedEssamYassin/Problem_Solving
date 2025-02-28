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
	ll N;
	// cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> N;
		/*
		The king wants to know the minimal number of soldiers he needs to recruit in order to kill all the dragons.
		The king doesn't care about the order of battles. (We can change the order of battles (Use sorting))

		To recruit the minimal number of soldiers, we need to sort the battles in a way such that we choose the battle that gives the maximum number of remaining soldiers first
		in order to recruit the minimum number of soldiers to be able to win the next battle
		*/
		vector<pair<ll, pair<ll, ll>>> V; // A vector to store pairs of {the remaining soldiers of each battle, a pair of {number of needed soldiers, number of killed soldiers}}
		while (N--)
		{
			cin >> a >> b;
			V.push_back({a - b, {a, b}});
		}
		sort(V.begin(), V.end(), greater<>()); // Sorting remaining soldiers in a descending order

		ll Minimum_number_of_soldiers{V[0].second.first};
		int number_of_needed_soldiers;
		int number_of_remaining_soldiers = V[0].first;
		for (int i{1}; i < V.size(); i++)
		{
			number_of_needed_soldiers = V[i].second.first;
			if (number_of_remaining_soldiers < number_of_needed_soldiers)
			{
				Minimum_number_of_soldiers += number_of_needed_soldiers - number_of_remaining_soldiers; // Recruiting more soldiers to reach the number_of_needed_soldiers
				number_of_remaining_soldiers = V[i].first;
			}
			else													// Remaining soldiers are enough to win the battle so we don't have to recruit more soldiers
				number_of_remaining_soldiers -= V[i].second.second; // Subtracting the number of killed soldiers
		}
		cout << Minimum_number_of_soldiers;
	}
	return 0;
}
