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
		string Line;
		bool Not_inside_comment = true;
		while (getline(cin, Line))
		{
			bool Printed = false;
			if (Line == "" or Line == " ") // If the line is empty or just a space
				continue;
			for (int i = 0; i < Line.size(); i++)
			{
				// --> A comment that is NOT inside a comment --> Do NOT print, ignore the whole line
				// This is a "*/" that is in NOT inside a comment --> It does NOT make Not_inside_comment = true
				/*
				--> Now we start to be inside a comment --> Not_inside_comment = false
				// --> This is a comment that is inside a multi-line comment
					   Do NOT ignore the whole line, it's possible to contain the comment closing */
				if (Line[i] == '/' && Line[i + 1] == '/' && Not_inside_comment)
					break;
				else if (Line[i] == '/' && Line[i + 1] == '*')
				{
					i++;
					Not_inside_comment = false; // Now we ALREADY are inside a comment
				}
				else if (Line[i] == '*' && Line[i + 1] == '/' && !Not_inside_comment)
				{
					i++;
					Not_inside_comment = true;
				}
				else if (Not_inside_comment)
				{
					cout << Line[i];
					Printed = true;
				}
			}
			if (Printed && Not_inside_comment)
				cout << endl;
		}
	}
	return 0;
}