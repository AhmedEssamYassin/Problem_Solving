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

	int N, K, rate;
	cin >> N >> K;
	vector<pair<int, int>> Teams; // Rate and position
	for (int i{1}; i <= N; i++)
	{
		cin >> rate;
		if (find_if(Teams.begin(), Teams.end(), [&](const pair<int, int> &P)
					{ return (rate == P.first); }) == Teams.end())
			Teams.push_back({rate, i});
	}
	if (Teams.size() < K)
		return cout << "NO", 0;

	cout << "YES\n";
	for (int i{}; i < K; i++)
		cout << Teams[i].second << " ";

	return 0;
}