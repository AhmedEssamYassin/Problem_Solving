#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	int N, M;
	string Direction, line;
	cin >> N >> M;
	cin >> Direction;
	/*
	Flipping Horizontally
	means to print each line reversed

	Flipping Vertically
	means to print ALL lines in a reversed order (From back to front)

	Flipping Diagonally
	means to print ALL lines in a reversed order (From back to front) and each line is reversed
	*/
	if (Direction == "Horizontally")
	{
		while (N--)
		{
			cin >> line;
			reverse(line.begin(), line.end());
			cout << line << endl;
		}
	}
	else if (Direction == "Vertically")
	{
		vector<string> Lines;
		while (N--)
		{
			cin >> line;
			Lines.push_back(line);
		}
		for (auto it = Lines.rbegin(); it != Lines.rend(); it++)
			cout << *it << endl;
	}
	else if (Direction == "Diagonally")
	{
		vector<string> Lines;
		while (N--)
		{
			cin >> line;
			Lines.push_back(line);
		}
		for (auto it = Lines.rbegin(); it != Lines.rend(); it++)
		{
			reverse(it->begin(), it->end());
			cout << *it << endl;
		}
	}

	return 0;
}