#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	char ch;
	cin >> ch;
	if (ch >= 48 && ch <= 57)
		cout << "IS DIGIT";
	else if (ch >= 65 && ch <= 90)
		cout << "ALPHA" << endl
			 << "IS CAPITAL";
	else if (ch >= 97 && ch <= 122)
		cout << "ALPHA" << endl
			 << "IS SMALL";
	return 0;
}
