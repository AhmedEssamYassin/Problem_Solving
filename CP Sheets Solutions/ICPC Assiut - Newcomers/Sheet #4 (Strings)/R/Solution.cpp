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
		int score{};
		cin >> N >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'V')
				score += 5;

			else if (str[i] == 'W')
				score += 2;

			else if (str[i] == 'X' && i != str.size() - 1)
				str[i + 1] = '\0';

			else if (str[i] == 'Y' && i != str.size() - 1)
			{
				str.push_back(str[i + 1]);
				str[i + 1] = '\0';
			}

			else if (str[i] == 'Z' && i != str.size() - 1)
			{
				if (str[i + 1] == 'V')
				{
					score /= 5;
					str[i + 1] = '\0';
				}
				else if (str[i + 1] == 'W')
				{
					score /= 2;
					str[i + 1] = '\0';
				}
			}
		}
		cout << score;
	}
	return 0;
}