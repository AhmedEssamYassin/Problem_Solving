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
		string str;
		cin >> str;
		transform(str.begin(), str.end(), str.begin(), ::tolower);

		int arr[5] = {0}; // To maintain the frequency of all characters of "egypt"
		for (const char &C : str)
		{
			if (C == 'e')
				arr[0]++;
			else if (C == 'g')
				arr[1]++;
			else if (C == 'y')
				arr[2]++;
			else if (C == 'p')
				arr[3]++;
			else if (C == 't')
				arr[4]++;
		}

		// We can always form a number of words as many as the minimum occurrence of all characters
		cout << *min_element(arr, arr + 5);
	}
	return 0;
}