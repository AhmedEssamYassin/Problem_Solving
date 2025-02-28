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
		cin >> N >> M;
		string S;
		/*
		Just output the chessboard like this:

		BWBWBWBW...

		WBWBWBWB...

		BWBWBWBW...

		...
		*/
		for (int i{}; i < N; i++)
		{
			cin >> S;
			for (int j{}; j < M; j++)
			{
				if (S[j] == '.')
				{
					if ((i + j) & 1) //(i + j) is ODD
						S[j] = 'W';
					else //(i + j) is EVEN
						S[j] = 'B';
				}
			}
			cout << S << endl;
		}
	}
	return 0;
}
