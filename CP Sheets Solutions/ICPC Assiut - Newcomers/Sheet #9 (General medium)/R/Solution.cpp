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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		string left_Pan, right_pan, weight, S;
		cin >> S;
		int pos = S.find('|');
		left_Pan = S.substr(0, pos);
		right_pan = S.substr(pos + 1);
		cin >> weight;
		for (int i{}; i < weight.length(); i++)
		{
			if (left_Pan.length() < right_pan.length())
				left_Pan += weight[i];
			else
				right_pan += weight[i];
		}
		if (left_Pan.length() == right_pan.length())
			cout << left_Pan << "|" << right_pan;
		else
			cout << "Impossible";
	}
	return 0;
}
