#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int X, Y;
	cin >> X >> Y;
	/*
	- Decimal representation: ... 10³ 10² 10¹ 10°
	- (X % 10) means the remaining of X after removing ALL multiples of 10, which are 10¹ 10² 10³ ...
	  that gives the ones which is the last digit
	- (X % 100) means the remaining of X after removing ALL multiples of 100, which are 10² 10³ ...
	  that gives the tens and the ones which are the last two digits
	and so on
	So, apparently, (X % 10^k) gives the last k digits of X
	*/
	cout << (X % 10) + (Y % 10);
	return 0;
}
