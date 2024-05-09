#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	char C;
	cin >> C;
	if (islower(C)) //(C >= 97 && C <= 122)
		C &= '_'; // '_' is 11011111 in binary

	else if (isupper(C)) //(C >= 65 && C <= 90)
		C |= ' '; // ' ' is 00100000 in binary
	cout << C;
	return 0;
}
