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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		string str;
		string temp("");
		cin >> str;
		bool open = false;
		int maxLenOut{}, cnt{}, len{};
		for (int i{}; i < N; i++)
		{
			len += (string("_()").find(str[i]) == -1 && not open);
			if (open && (string("_()").find(str[i]) == -1))
				temp += str[i];

			if (str[i] == '(')
				open = true, maxLenOut = max(maxLenOut, len), len = 0;
			else if (str[i] == ')')
				open = false, cnt += (not temp.empty()), temp = "";
			else if ((string("_(").find(str[i]) != -1 && not open) || i == N - 1)
			{
				maxLenOut = max(maxLenOut, len);
				len = 0;
			}
			else if (str[i] == '_' && open)
				cnt += (not temp.empty()), temp = "";
		}
		cout << maxLenOut << " " << cnt;
	}
	return 0;
}