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
	Original price = Price after discount + Discount percentage * Original price
	Original price - Discount percentage * Original price = Price after discount
	(1 - Discount percentage) * Original price = Price after discount
	Original price = Price after discount / (1 - Discount percentage)
	*/

	// To print numbers in fixed floating-point representation (NOT scientific notation, i.e. NOT e or E exponentiation notation)
	cout << fixed;

	// To print numbers with precision of two decimal places
	cout << setprecision(2);

	double Discount_percentage, Price_after_discount;
	cin >> Discount_percentage >> Price_after_discount;
	cout << ((Price_after_discount) / (1 - Discount_percentage / 100));
	return 0;
}