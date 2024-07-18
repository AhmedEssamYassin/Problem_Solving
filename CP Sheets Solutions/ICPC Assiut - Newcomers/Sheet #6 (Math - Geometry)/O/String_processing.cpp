#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

string Multiply(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0 || len2 == 0)
		return "0";

	vector<int> result(len1 + len2, 0);

	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1
	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;

		// Go from right to left in num2
		for (int j = len2 - 1; j >= 0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum / 10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
		return "0";

	// generate the result string
	string s = "";

	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

string Add(string num1, string num2)
{
	string a = num1;
	string c = num2;
	int alen = a.length(), clen = c.length();
	int n = max(alen, clen);
	if (alen > clen)
		c.insert(0, alen - clen, '0');
	else if (alen < clen)
		a.insert(0, clen - alen, '0');
	string res(n + 1, '0');
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int digit = (a[i] - '0') + (c[i] - '0') + carry;
		carry = digit / 10;
		res[i + 1] = digit % 10 + '0';
	}
	if (carry == 1)
	{
		res[0] = '1';
		return res;
	}
	else
		return res.substr(1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string num1, num2;
		cin >> num1 >> num2;
		cout << Add(num1, "9999") << endl;
		cout << Multiply(num1, "9999");
	}
	return 0;
}