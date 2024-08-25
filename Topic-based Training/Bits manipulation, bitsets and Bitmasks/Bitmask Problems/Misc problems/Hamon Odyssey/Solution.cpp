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
	There are two cases in this problem.
	- First, if f(1,n) > 0
	, then maximum number of groups becomes 1
	This is because there are some bits set in all the elements.
	Now, if we divide the array in more than one group, then these bits are taken more than once which will not give smallest AND.

	- Second case is when f(1,n)=0
	This means the smallest AND is 0
	Now, we need to greedily divide the array into sub-arrays such that the AND of each sub-array should be 0
	We keep taking elements in the sub-array until the AND becomes 0
	When AND becomes 0, we take remaining elements in the next sub-array.
	If the last sub-array has AND more than 0, then we need to merge that sub-array with the previous sub-array.
	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		ll curAND = -1; // has ALL bits set in binary (2's complement)
		for (int i{}; i < N; i++)
			cin >> vc[i];

		int cnt{1};
		for (int i{}; i < N; i++)
		{
			curAND &= vc[i];
			if (curAND == 0)
			{
				if (i == N - 1)
					break;
				cnt++;
				curAND = -1;
			}
		}
		if (curAND > 0)
			cnt--;
		cout << max(cnt, 1) << endl;
	}
	return 0;
}