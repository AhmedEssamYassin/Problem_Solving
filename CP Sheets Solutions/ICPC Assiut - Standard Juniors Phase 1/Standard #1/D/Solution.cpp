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

	int N, M, X;
	cin >> N >> M;
	int *Freq_neg_numbers{new int[M + 1]{0}};
	int *Freq_pos_numbers{new int[M + 1]{0}};
	while (N--)
	{
		cin >> X;
		if (X > 0)
			Freq_pos_numbers[X]++;
		else if (X < 0)
			Freq_neg_numbers[-X]++;
	}
	int ans = -1e6; // A value that is guaranteed NOT to be an input
	for (int i{M}; i >= 0; i--)
		if (Freq_neg_numbers[i] == 0)
		{
			ans = -i;
			break;
		}
	if (ans == -1e6)
		for (int i{0}; i <= M; i++)
			if (Freq_pos_numbers[i] == 0)
			{
				ans = i;
				break;
			}
	cout << ans;
	delete[] Freq_neg_numbers;
	delete[] Freq_pos_numbers;

	return 0;
}