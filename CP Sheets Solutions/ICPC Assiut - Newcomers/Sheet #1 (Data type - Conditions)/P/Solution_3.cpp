#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string Number;
	cin >> Number;
	if ((Number.front() - '0') & 1)
		cout << "ODD";
	else
		cout << "EVEN";
	return 0;
}
