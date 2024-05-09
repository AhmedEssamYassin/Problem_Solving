/*
Magic powder 1, 2
Link 1 : https://codeforces.com/contest/670/problem/D1
Link 2 : https://codeforces.com/contest/670/problem/D2
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int n, k;
vector<int> need, have;
bool OK(ll Num_of_cakes)
{
	ll magic_Powder = k;
	for (int i = 0; i < n; i++)
	{
		if (Num_of_cakes * need[i] > have[i])
		{
			magic_Powder -= 1ll * Num_of_cakes * need[i] - have[i];
		}
		if (magic_Powder < 0) // we don't have enough of magic_Powder to make this Num_of_cakes
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		need.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		have.push_back(x);
	}

	ll res{}; // To print 0 if we can't make any cakes (No  OK mid found)
	ll l{}, r = 2000000000, mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2; // To avoid Overflow
		if (OK(mid))
		// if mid is OK, all before mid is also OK. So we set our result initially = mid then move the left pointer (mid+1) hoping to find a larger
		// number of cakes to be OK too otherwise, result still = mid and so on
		{
			res = mid;
			l = mid + 1;
		}
		else
			// if mid is NOT OK, all after mid is NOT OK either. So we move the right pointer to (mid-1) and continue searching in the remaining space
			r = mid - 1;
	}
	cout << res;
	return 0;
}