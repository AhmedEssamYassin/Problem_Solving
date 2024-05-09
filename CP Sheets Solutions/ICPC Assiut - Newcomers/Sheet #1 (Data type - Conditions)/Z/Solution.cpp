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

	/*
	(A^B)  and  (C^D) , Taking their constraints into consideration, will difinitely OVERFLOW any data type in C++ (in worst case scenarios)
	So, we must use the mathematical property of logarithms (POWER PROPERTY):
	logₐ m^n = n logₐ m
	*/
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	if (B * log(A) > D * log(C))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}