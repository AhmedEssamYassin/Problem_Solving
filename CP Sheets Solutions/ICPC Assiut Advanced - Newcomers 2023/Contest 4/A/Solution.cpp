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

	ll Apples_on_tree, Apples_pm;
	cin >> Apples_on_tree >> Apples_pm;
	/*
	Minutes = Apples_on_tree / Apples_pm
	Example:
	Apples_on_tree = 22
	Apples_pm = 4
	22 / 4 = 5.5 minutes,
	but fractions aren't allowed, It's required to find the minimum integer number of minutes needed to eat all Apples_on_tree
	So obviously, we need to ceil the answer
	*/
	cout << (Apples_on_tree + Apples_pm - 1) / Apples_pm;

	return 0;
}