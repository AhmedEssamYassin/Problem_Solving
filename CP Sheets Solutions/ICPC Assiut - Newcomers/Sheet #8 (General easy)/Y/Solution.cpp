#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool comp(const vector<int> &vc1, const vector<int> &vc2)
{
	return vc1.size() < vc2.size();
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		int type;
		cin >> N;
		vector<int> arr[3]; // array of 3 vectors, it means three rows but each row is of a variable size
		// each row represents one of the t's: 1, 2 or three but (0-indexed), i.e, 0, 1 and 2
		// in each row (vector), we will push values representing the indices (1-indexed) of occurrence of 0, 1 and 2 (previously denoted as 1, 2 and 3)

		for (int i = 1; i <= N; i++)
		{
			cin >> type;
			arr[type - 1].push_back(i);
		}

		sort(arr, arr + 3, comp); // sorting the array in ascending order on basis of the size of its vectors
		int cnt = arr[0].size();  // the minimum occurrence of 0, 1 and 2
		// Because we can ONLY make a number of STH equal to the minimum quantity of one of its needed components
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			cout << arr[0][i] << " " << arr[1][i] << " " << arr[2][i] << endl;
	}
	return 0;
}
