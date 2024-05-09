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
	int N;
	cin >> N;
	/*
	Each cell can be either one of those:
	1. The ghost is in the cell represented by the letter 'G'
	2. Shaggy is in the cell, represented by the letter 'H'
	3. Scooby-Doo is in the box represented by the letter 'S'
	4. The Exit door is represented by a the letter 'E'
	5. Empty cell represented by the symbol '∗'

	There is ONLY one of each of them.

	For 'S' and 'H', to be able to unseenly escape the ghost 'G',
	1. They MUST NOT exist on the same floor
	2. They MUST NOT encounter the ghost 'G' on their way to the EXIT door 'E'
	i.e.
	If there are 4 floors
	1st: **S*
	2nd: **H*
	2rd: *G**
	4th: ***E
	Although they are NOT on the same floor with the ghost 'G', they CANNOT escape
	because they will HAVE TO encounter the ghost 'G' on the 3rd floor on their way to 'E' which is on the 4th floor
	*/
	string Floor;
	int pos_S, pos_H, pos_E, pos_G; // To store the position of the floor on which each of them is existing right now

	for (int i{}; i < N; i++) // To traverse floors
	{
		cin >> Floor;

		// Traversing floors downwards
		for (int j{}; j < N; j++)
		{
			if (Floor.find("G") != -1) // If a Ghost exists
			{
				if ((Floor.find("H") != -1) || (Floor.find("S") != -1)) // If ONE of 'S' or 'H' exists at the same time
					return cout << "Ruh-roh--RAGGY!!!", 0;
			}

			if (Floor.find("H") != -1)
				pos_H = i;
			if (Floor.find("S") != -1)
				pos_S = i;
			if (Floor.find("E") != -1)
				pos_E = i;
			if (Floor.find("G") != -1)
				pos_G = i;
		}
	}

	if ((pos_S > pos_G && pos_H > pos_G && pos_E > pos_G)	  // If 'S', 'H' and the EXIT door 'E' ALL exist AFTER the ghost 'G'
		|| (pos_S < pos_G && pos_H < pos_G && pos_E < pos_G)) // If 'S', 'H' and the EXIT door 'E' ALL exist BEFORE the ghost 'G'
		cout << "Scooby-Dooby-Doo!";
	else
		cout << "Ruh-roh--RAGGY!!!";
	return 0;
}