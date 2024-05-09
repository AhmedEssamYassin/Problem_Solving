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

	short int N;
	cin >> N;
	int *arr = new int[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	vector<vector<int>> Ans;
	for (int i = 0; i < (1 << N); i++)
	{
		// Loop through all elements of the input array
		vector<int> Temp;
		for (int j = 0; j < N; j++)
		{
			// Check if the jth bit is set in the current subset
			if (i & (1 << j))
			{
				// If the jth bit is set, add the jth element to the subset
				Temp.push_back(arr[j]);
			}
		}
		Ans.push_back(Temp);
	}
	sort(Ans.begin(), Ans.end());
	for (auto &subset : Ans)
	{
		for (auto &number : subset)
			cout << number << " ";
		cout << endl;
	}
	delete[] arr;
	return 0;
}