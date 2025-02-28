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
		ll SerejaSum = 0, DimaSum = 0;
		cin >> N;
		deque<int> cards(N);
		for (int i = 0; i < N; i++)
			cin >> cards[i];
		bool turn = false;
		while (!cards.empty())
		{
			if (turn = !turn)
			{
				if (cards.front() > cards.back())
				{
					SerejaSum += cards.front();
					cards.pop_front();
				}
				else
				{
					SerejaSum += cards.back();
					cards.pop_back();
				}
			}
			else
			{
				if (cards.front() > cards.back())
				{
					DimaSum += cards.front();
					cards.pop_front();
				}
				else
				{
					DimaSum += cards.back();
					cards.pop_back();
				}
			}
		}
		cout << SerejaSum << " " << DimaSum << endl;
	}
	return 0;
}
