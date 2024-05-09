#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int Left_operand, Right_operand;
	char Sign;
	cin >> Left_operand >> Sign >> Right_operand;
	if (Sign == '+')
		cout << Left_operand + Right_operand;
	else if (Sign == '-')
		cout << Left_operand - Right_operand;
	else if (Sign == '*')
		cout << Left_operand * Right_operand;
	else if (Sign == '/')
		cout << Left_operand / Right_operand;
	return 0;
}
