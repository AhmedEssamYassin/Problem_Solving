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

	int N, Q;
	int t, x;
	cin >> N >> Q;
	int *Freq_arr{new int[N + 1]{0}};
	while (Q--)
	{
		cin >> t >> x;
		if (t == 1)
			Freq_arr[x]++;
		else
			cout << Freq_arr[x] << endl;
	}
	delete[] Freq_arr;

	return 0;
}