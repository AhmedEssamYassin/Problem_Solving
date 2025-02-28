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
		vector<ll> arr(N), freqArr(1000001, 0);
		ll Sum{};
		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			freqArr[arr[i]]++;
			Sum += arr[i];
		}

		/*
		For a sum to be represented as two parts:
		One part is an element let's call it X, and the other part is ALL other elements whose sum is equal to X
		- That sum MUST be:
		  1. EVEN (to be divisible by 2)
		  2. in range [1, 1000'000] (which is the given constrain on elements)
		  The second condition is important in order NOT to check on existence of an element > 1e6 in the frequency array
		  because that will cause Runtime Error!
		  Or just use an std::map
		*/
		vector<int> Ans; // To store nice indices
		for (int i{}; i < N; i++)
		{
			ll Val = (Sum - arr[i]);
			freqArr[arr[i]]--; // Decreasing frequency by 1 (as if we remove it from array)
			if (Val % 2 == 0 && Val / 2 <= 1000'000 && freqArr[Val / 2] > 0)
				Ans.push_back(i + 1); // To store 1-based indices

			freqArr[arr[i]]++; // Increasing frequency by 1 (as if we are returning it back to array)
		}
		cout << Ans.size() << endl;
		for (int i{}; i < Ans.size(); i++)
			cout << Ans[i] << " ";
	}
	return 0;
}
