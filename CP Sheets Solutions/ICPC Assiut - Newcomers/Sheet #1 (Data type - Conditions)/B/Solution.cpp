#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int i_var;
	long long int ll_var;
	char ch_var;
	float f_var;
	double d_var;
	cin >> i_var >> ll_var >> ch_var >> f_var >> d_var;
	cout << fixed;
	/*
	- Write floating-point values in fixed-point notation.
	- When floatfield is set to fixed, floating-point values are written using fixed-point notation:
	the value is represented with exactly as many digits in the decimal part as specified by the precision field (precision) and with NO exponent part.
	*/
	cout << i_var << endl;
	cout << ll_var << endl;
	cout << ch_var << endl;
	cout << f_var << endl;
	cout << d_var << endl;
	return 0;
}
