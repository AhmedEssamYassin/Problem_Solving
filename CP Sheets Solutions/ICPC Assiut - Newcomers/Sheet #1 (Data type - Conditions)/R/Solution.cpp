#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int Days;
	cin >> Days;
	/*
	(A / B) means How many B's in A
	(A / B) Also means How many multiples of B in range [1, A]

	(A % B) means what is the remaining of A if we subtract all B's
	*/

	cout << Days / 365 << " years" << endl; // How many years exist in that number of days

	Days %= 365; // What remains of Days after subtracting all those years

	cout << Days / 30 << " months" << endl; // How many months exist in that number of days

	Days %= 30; // What remains of Days after subtracting all those months
	cout << Days << " days" << endl;
	return 0;
}
