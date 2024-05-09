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
	while (t--)
	{
		string str;
		int arr[26];
		cin >> str;
		for (int i{}; i < 26; i++)
			cin >> arr[i];

		char c, end, start;
		int min_cost = INT_MAX, l, r;
		// Handling the case where all the string is '?' such as "????????????"
		if (all_of(str.begin(), str.end(), [](char i)
				   { return i == '?'; }))
			return cout << "0\n"
						<< string(str.length(), 'a'),
				   0;
		//----------------------------------------------------------------------------------------------------------------------------
		// Handling the case where the first one or more characters are '?' (but there are other characters) such as "?????????abds"
		if (str.front() == '?')
		{
			for (int i{}; i < str.length(); i++)
			{
				if (str[i] != '?')
				{
					end = str[i];
					r = i - 1;
					break;
				}
			}
			for (int i{}; i < 26; i++)
			{
				if (abs(arr[end - 97] - arr[i]) < min_cost)
					min_cost = abs(arr[end - 97] - arr[i]), c = i + 97;
			}
			for (int i{}; i <= r; i++)
				str[i] = c;
		}
		//----------------------------------------------------------------------------------------------------------------------------
		min_cost = INT_MAX;
		// Handling the case where the last one or more characters are '?' (but there are other characters) such as "abd?????????"
		if (str.back() == '?')
		{
			for (int i = str.size() - 2; i >= 0; i--)
			{
				if (str[i] != '?')
				{
					start = str[i];
					l = i + 1;
					break;
				}
			}
			for (int i{}; i < 26; i++)
			{
				if (abs(arr[start - 97] - arr[i]) < min_cost)
					min_cost = abs(arr[start - 97] - arr[i]), c = i + 97;
			}
			for (int i{l}; i < str.length(); i++)
				str[i] = c;
		}
		// Handling the case where there are '?' within the string such as "abd??efgh?ijk"
		for (int i{}; i < str.length(); i++)
		{
			if (str[i] == '?')
			{
				min_cost = INT_MAX;
				l = i;
				start = str[i - 1];
				while (str[i] == '?') // ahmed???yassin
					i++;
				r = i - 1;
				end = str[i];
				for (int j{}; j < 26; j++)
				{
					int curr_cost = abs(arr[start - 97] - arr[j]) + abs(arr[end - 97] - arr[j]);
					if (curr_cost < min_cost)
						min_cost = curr_cost, c = j + 97;
				}
				for (int j{l}; j <= r; j++)
					str[j] = c;
			}
		}
		ll total_cost{};
		for (int i{1}; i < str.length(); i++)
			total_cost += abs(arr[str[i] - 97] - arr[str[i - 1] - 97]);
		cout << total_cost << endl
			 << str;
	}
	return 0;
}