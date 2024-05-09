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
		// http://www.{word}.{word}/{word}/{word}?username={word}&pwd={word}&profile={word}&role={word}&key={word}
		string str;
		getline(cin, str);
		str = str.substr(str.find('?') + 1);
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] == '=')
			{
				cout << ": ";
				continue;
			}
			if (str[i] == '&')
			{
				cout << endl;
				continue;
			}
			cout << str[i];
		}
	}
	return 0;
}