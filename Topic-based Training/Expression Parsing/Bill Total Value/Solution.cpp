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
#endif //! ONLINE_JUDGE
	int t = 1;
	int N;
	// cin >> t;
	string bill;
	while (t--)
	{
		// chipsy48.32televizor12.390
		cin >> bill;
		long double ans{};
		string temp("");
		int i{};
		for (const char &C : bill)
		{
			if (!isalpha(C))
				temp += C;
			if (isalpha(C) || i == bill.length() - 1)
			{
				if (not temp.empty())
				{
					int floating{};
					for (int idx = temp.length() - 1; idx >= 0; idx--)
					{
						if (isdigit(temp[idx]))
							floating++;
						else
						{
							if (floating > 2)
								temp.erase(temp.begin() + idx);
							floating = 0;
						}
					}
					ans += stold(temp);
					temp.clear();
				}
			}
			i++;
		}

		string totalPrice = to_string(ans);
		// 12.438.32
		int pos = totalPrice.rfind('.'); // Find the last '.'

		int cnt{1};
		for (int i{pos - 1}; i >= 0; i--)
		{
			if (cnt++ == 3 && i > 0)
				totalPrice.insert(totalPrice.begin() + i, '.'), cnt = 1;
		}
		while (totalPrice.back() == '0')
			totalPrice.pop_back();
		pos = totalPrice.rfind('.'); // Find the last '.'
		if (totalPrice.back() == '.')
			totalPrice.pop_back();

		else if (totalPrice.length() - 1 - pos == 1) // 0 1 2 3 4
			totalPrice.push_back('0');

		cout << totalPrice;
	}
	return 0;
}