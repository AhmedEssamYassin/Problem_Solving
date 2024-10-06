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
		string RBS;
		stack<char> stk;
		cin >> RBS;
		if (RBS.length() == 1)
			return cout << "Impossible\n", 0;
		bool flag = true;
		int cnt{};
		if (string("[{(<").find(RBS[0]) != -1)
			stk.push(RBS[0]);
		for (int i{1}; i < RBS.length(); i++)
		{
			char C = RBS[i];
			if (string("[{(<").find(C) != -1)
				stk.push(C);

			else if (stk.empty())
			{
				flag = false;
				break;
			}
			else
			{
				char Top = stk.top();
				if ((C == '}' && Top != '{') || (C == ']' && Top != '[') || (C == '>' && Top != '<') || (C == ')' && Top != '('))
					cnt++;
				stk.pop();
			}
		}
		if (flag && stk.empty())
			cout << cnt << endl;
		else
			cout << "Impossible\n";
	}
	return 0;
}