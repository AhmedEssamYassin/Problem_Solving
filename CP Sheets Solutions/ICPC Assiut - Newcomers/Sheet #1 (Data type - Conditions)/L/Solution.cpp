#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string First_name1, Surname1, First_name2, Surname2;
	cin >> First_name1 >> Surname1;
	cin >> First_name2 >> Surname2;
	if (Surname1 == Surname2)
		cout << "ARE Brothers";
	else
		cout << "NOT";
	return 0;
}
