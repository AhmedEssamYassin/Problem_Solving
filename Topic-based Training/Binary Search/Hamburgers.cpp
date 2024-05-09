/*
Hamburgers
Link: https://codeforces.com/problemset/problem/371/C
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
ll r;
vector<int> price(3), have(3), amount(3);
bool OK(ll Num_of_Hams)
{
	ll money = r;
	for (int i = 0; i < 3; i++)
	{
		if (Num_of_Hams * amount[i] > have[i])
		{
			money -= (Num_of_Hams * amount[i] - have[i]) * price[i];
		}
		if (money < 0) // we don't have enough of money to make this Num_of_Hams
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	// Stores the amount needed of every component to make a one whole Hamburger
	for (char c : s)
	{
		if (c == 'B')
			amount[0]++;
		else if (c == 'S')
			amount[1]++;
		else
			amount[2]++;
	}
	// Stores the amount we actually have of every component
	for (int i = 0; i < 3; i++)
		cin >> have[i];
	// Stores the price of every component
	for (int i = 0; i < 3; i++)
		cin >> price[i];

	cin >> r; // the total money we have

	ll res{}; // To print 0 if we can't make any Hamburgers (No  OK mid found)
	ll l{}, h = 200000000000000, mid;
	while (l <= h)
	{
		mid = l + (h - l) / 2; // To avoid Overflow
		if (OK(mid))
		// if mid is OK, all before mid is also OK. So we set our result initially = mid then move the left pointer (mid+1) hoping to find a larger
		// number of Hamburgers to be OK too otherwise, result still = mid and so on
		{
			res = mid;
			l = mid + 1;
		}
		else
			// if mid is NOT OK, all after mid is NOT OK either. So we move the right pointer to (mid-1) and continue searching in the remaining space
			h = mid - 1;
	}
	cout << res;
	return 0;
}