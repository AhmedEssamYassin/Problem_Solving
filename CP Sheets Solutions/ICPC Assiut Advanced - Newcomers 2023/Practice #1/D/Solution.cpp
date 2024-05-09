#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool On_basis_of_second(const pair<int, int> &P1, const pair<int, int> &P2)
{
	return P1.second < P2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int S, N;
	cin >> S >> N;

	vector<pair<int, int>> Dragons(N);
	for (int i{}; i < N; i++)
		cin >> Dragons[i].first >> Dragons[i].second;

	sort(Dragons.begin(), Dragons.end());

	for (int i{}; i < N; i++)
	{
		if (S > Dragons[i].first)
			S += Dragons[i].second;
		else
			return cout << "NO", 0;
	}
	cout << "YES";

	return 0;
}