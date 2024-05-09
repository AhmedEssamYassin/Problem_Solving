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

	int N;
	cin >> N;
	/*
	input: N
	- Number of lines = N

	- Each line has N characters

	- ALL characters are '*' EXCEPT:
	  Characters on the main diagonal are '\\'
	  Characters on the secondary diagonal are '/'
	  Character at the intercept of both diagonals is 'X
	*/
	for (int i = 1; i <= N; i++)
	{
		string Line(N, '*');
		Line[i - 1] = '\\';
		Line[N - i] = '/';
		if (i == (N + 1) / 2)
			Line[i - 1] = 'X';

		cout << Line << endl;
	}

	return 0;
}