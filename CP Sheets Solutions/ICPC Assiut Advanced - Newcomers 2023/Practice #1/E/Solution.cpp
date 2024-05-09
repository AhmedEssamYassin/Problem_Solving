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
	/*
	t = 1, if the i-th child is good at programming,
	t = 2, if the i-th child is good at maths,
	t = 3, if the i-th child is good at PE
	The school teachers decided that the teams will be composed of three children that are good at different subjects.
	That is, each team must have one mathematician, one programmer and one sportsman. Of course, each child can be a member of no more than one team.

	What is the maximum number of teams that the school will be able to present at the Olympiad? How should the teams be formed for that?

	In the first line output integer w — the largest possible number of teams.
	Then print w lines, containing three numbers in each line.
	Each triple represents the indices of the children forming the team.
	You can print both the teams, and the numbers in the triplets in any order.
	The children are numbered from 1 to N in the order of their appearance in the input.
	Each child must participate in NO more than one team. If there are several solutions, print any of them.

	If NO teams can be compiled, print the only line with value w equal to 0.
	*/
	int N, t;
	cin >> N;
	vector<vector<uint32_t>> Vec(4); // To represent t's: 1, 2 and 3
	// Each index represents the subject they are good at i.e., t,
	// each t has a vector which stores the indices of the children who are good at that t

	for (int i{1}; i <= N; i++)
	{
		cin >> t;
		Vec[t].push_back(i);
	}

	// Number of teams to be presented is the minimum number of children good at any of the three t's
	int Number_of_teams = min({Vec[1].size(), Vec[2].size(), Vec[3].size()});

	cout << Number_of_teams << endl;
	if (Number_of_teams)
	{
		for (int i{}; i < Number_of_teams; i++)
			cout << Vec[1][i] << " " << Vec[2][i] << " " << Vec[3][i] << endl; // Pick a child who is good at each subject
	}

	return 0;
}