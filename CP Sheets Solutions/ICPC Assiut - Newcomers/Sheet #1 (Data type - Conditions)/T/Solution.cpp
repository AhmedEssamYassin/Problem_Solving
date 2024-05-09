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

	vector<int> Vec(3);
	for (int i = 0; i < 3; i++)
		cin >> Vec[i];

	vector<int> Copy_Vec(Vec);
	sort(Vec.begin(), Vec.end());
	cout << Vec[0] << endl
		 << Vec[1] << endl
		 << Vec[2] << endl
		 << endl;
	cout << Copy_Vec[0] << endl
		 << Copy_Vec[1] << endl
		 << Copy_Vec[2];
	return 0;
}