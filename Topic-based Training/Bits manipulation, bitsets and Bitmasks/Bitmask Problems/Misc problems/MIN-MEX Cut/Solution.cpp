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
	/*
	There are ONLY 3 cases:
	1. There is NO 0 in the string : Just take the whole string and the sum of MEX is 0

	2. All zeroes create a single segment without ones : Then we can cut this segment out, its MEX is 1,
	everything else is ones, their total MEX is 0. So, The sum of MEX is 1.

	3. If neither case 1 nor case 2: The answer is always 2
	*/
	int t = 1;
	ll N;
	string binStr;
	cin >> t;
	while (t--)
	{
		cin >> binStr;
		if (binStr.find('0') == -1)
		{
			cout << 0 << endl;
			continue;
		}
		int firstZero = binStr.find('0');
		int lastZero = binStr.rfind('0');
		if (lastZero - firstZero + 1 == count(binStr.begin(), binStr.end(), '0'))
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}