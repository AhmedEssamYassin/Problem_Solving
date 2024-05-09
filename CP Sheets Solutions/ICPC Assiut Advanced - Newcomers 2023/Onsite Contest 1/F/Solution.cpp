#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;
	/*
	- Each team must consist of exactly 3 people, at that, any person CANNOT be a member of two or more teams.
	- For each team, to participate in the world championship with the same members at least K times ( >= K ),
	  it MUST consist of 3 members who participated AT MOST (5-K) times before
	So, the problem is to count how many 3's (teams) can be formed from all persons who participated a number of times <= (5 - K)
	*/
	int Number_Of_Times;
	int cnt{};
	while (N--)
	{
		cin >> Number_Of_Times;
		if (Number_Of_Times <= (5 - K))
			cnt++;
	}
	cout << cnt / 3;

	return 0;
}