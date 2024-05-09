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
#endif // !ONLINE_JUDGE

	/*
	First, note that parts of the picture separated by 'W' are independent.
	That is, any stamps used on one part does NOT have any impact on the other, since a character 'W' means no stamp has been placed on that cell.
	So let's split the string by W's, and consider the resulting strings containing only R and B.
	Call one of these parts p
	In the final stamp we place on p, we must have placed RB, so it should have both the characters R and B. Therefore, if the string has only R or only B, the answer is NO.
	Otherwise, it can be made and the answer is YES.
	*/
	int t, N;
	regex R_reg("R{1,}");
	regex B_reg("B{1,}");
	cin >> t;
	while (t--)
	{
		cin >> N;
		char *str = new char[N + 1];
		for (int i{}; i < N; i++)
			cin >> str[i];
		str[N] = '\0';
		bool flag = true;
		char *token = strtok(str, "W\0");
		while (token != nullptr)
		{
			if (regex_match(token, R_reg) || regex_match(token, B_reg))
			{
				cout << "NO\n";
				flag = false;
				break;
			}

			token = strtok(nullptr, "W\0");
		}
		if (flag)
			cout << "YES\n";

		delete[] str;
	}

	return 0;
}