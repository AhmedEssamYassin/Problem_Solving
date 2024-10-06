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
		string email;
		cin >> email;
		int posAt = email.find("at", 1);
		string parsedEmail("");
		for (int i{}; i < posAt; i++)
		{
			if (email.substr(i, 3) == "dot")
			{
				if (not parsedEmail.empty())
					parsedEmail += '.';
				else
					parsedEmail += "dot";
				i += 2;
			}
			else
				parsedEmail += email[i];
		}
		parsedEmail += '@';
		for (int i = posAt + 2; i < email.length(); i++)
		{
			if (email.substr(i, 3) == "dot")
			{
				if (i + 2 == email.length() - 1)
					parsedEmail += "dot";
				else
					parsedEmail += '.';
				i += 2;
			}
			else
				parsedEmail += email[i];
		}
		cout << parsedEmail << endl;
	}
	return 0;
}