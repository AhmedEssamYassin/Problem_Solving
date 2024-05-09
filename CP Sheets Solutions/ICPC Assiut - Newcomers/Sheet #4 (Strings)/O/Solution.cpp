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
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		char C;
		int arr[26] = {0}; // ALL frequencies of elements are now equal to 0
		for (int i = 0; i < N; i++)
		{
			cin >> C;
			arr[C - 97]++;
		}

		for (int i{}; i < 26; i++)
		{
			while (arr[i]--)
				cout << char(i + 97);
		}
	}
	return 0;
}