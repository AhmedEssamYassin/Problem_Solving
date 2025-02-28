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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		int *arr = new int[N];
		ll EVEN_pref{}, EVEN_suf{}, ODD_pref{}, ODD_suf{};
		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			// Positions are: 0 1 2 3 4 5 ...
			// (i & 1) is true when i is 1 3 5 which are the second, fourth, sixth ... elements (the even positions)
			if (i & 1) // EVEN position
				EVEN_suf += arr[i];
			else // ODD position
				ODD_suf += arr[i];
		}
		/*
		The problem is that when we delete any element it flips the parity of ALL its following elements
		So we maintain 4 variables:
		EVEN_suf, ODD_suf (easily computed bu summing all elements in odd or even positions)
		EVEN_pref, ODD_pref (computed dynamically while traversing the array and checking every possible element)
		at each element, we subtract it from its suffix sum
		Then the addends of ODD_suf become ALL EVEN and the addends of EVEN_suf become ALL ODD (Parity flips)
		That's why we check if (EVEN_pref + ODD_suf == ODD_pref + EVEN_suf)
		*/
		int cnt{};
		for (int i{}; i < N; i++)
		{
			if (i & 1) // EVEN pos
				EVEN_suf -= arr[i];

			else // ODD pos
				ODD_suf -= arr[i];

			if (EVEN_pref + ODD_suf == ODD_pref + EVEN_suf)
				cnt++;

			if (i & 1) // EVEN pos
				EVEN_pref += arr[i];
			else // ODD pos
				ODD_pref += arr[i];
		}
		cout << cnt << endl;
		delete[] arr;
	}
	/*
	Tracing a case:
	2 3 4 2 2 3 2 2 4
	EVEN_suf = 10
	ODD_suf = 14
	if (EVEN_pref + ODD_suf == ODD_pref + EVEN_suf) count 1

	at 2: ODD_suf = 12, EVEN_suf = 10, ODD_pref = 0, EVEN_pref = 0
	at 3: ODD_suf = 12, EVEN_suf = 7,  ODD_pref = 2, EVEN_pref = 0
	at 4: ODD_suf = 8,  EVEN_suf = 7,  ODD_pref = 2, EVEN_pref = 3
	at 2: ODD_suf = 8,  EVEN_suf = 5,  ODD_pref = 6, EVEN_pref = 3 		counts 1
	at 2: ODD_suf = 6,  EVEN_suf = 5,  ODD_pref = 6, EVEN_pref = 5 		counts 1
	at 3: ODD_suf = 6,  EVEN_suf = 2,  ODD_pref = 8, EVEN_pref = 5
	at 2: ODD_suf = 4,  EVEN_suf = 2,  ODD_pref = 8, EVEN_pref = 8
	at 2: ODD_suf = 4,  EVEN_suf = 0,  ODD_pref = 10,EVEN_pref = 8
	at 4: ODD_suf = 0,  EVEN_suf = 0,  ODD_pref = 10,EVEN_pref = 10 	counts 1
	So The answer is 3
	*/
	return 0;
}
