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
	int t = 1, N;
	cin >> t;
	while (t--)
	{
		int EVEN_cnt{}, ODD_cnt{};
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			if (arr[i] & 1) // ODD
				ODD_cnt++;
			else // EVEN
				EVEN_cnt++;
		}
		int diff = abs(ODD_cnt - EVEN_cnt);
		if (diff == 0)
			cout << 0 << endl;
		else if (diff & 1)
			cout << -1 << endl;
		else
			cout << diff / 2 << endl;
		delete[] arr;
	}
	return 0;
}