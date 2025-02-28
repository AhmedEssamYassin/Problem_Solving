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
		set<int> NO_duplicate_arr;
		int *arr = new int[N];
		int freqArr[1000'01] = {0}; // Retrieval (Access) is O(1)

		for (int i{}; i < N; i++)
		{
			cin >> arr[i];
			NO_duplicate_arr.insert(arr[i]); // Sorted and NO duplicates (Distinct)
			freqArr[arr[i]]++;
		}

		vector<int> To_remove; // To record elements whose frequency became 0 to remove from set
		while (!NO_duplicate_arr.empty())
		{
			for (const auto &itr : NO_duplicate_arr)
			{
				cout << itr << " ";
				freqArr[itr]--; // Decrease frequency
				if (freqArr[itr] == 0)
					To_remove.push_back(itr);
			}
			cout << endl;
			for (const auto &i : To_remove)
				NO_duplicate_arr.erase(i);
			To_remove.clear(); // To record new elements to remove
		}

		delete[] arr;
	}
	return 0;
}
