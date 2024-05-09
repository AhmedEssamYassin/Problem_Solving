#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// clubs comes before diamonds,
// which comes before hearts,
// which comes before spades
string pos("AKQJ");
bool predFunc(const string &card1, const string &card2)
{
	if (isdigit(card1[0]) || isdigit(card2[0]))
	{
		if (card1[0] == card2[0])
			return card1[1] < card2[1];
		return card1[0] < card2[0];
	}
	else
	{
		if (card1[0] == card2[0])
			return card1[1] < card2[1];
		return pos.find(card1[0]) > pos.find(card2[0]);
	}
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<string> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		sort(vc.begin(), vc.end(), predFunc);
		for (int i{}; i < N; i++)
			cout << vc[i] << " ";
	}
	return 0;
}