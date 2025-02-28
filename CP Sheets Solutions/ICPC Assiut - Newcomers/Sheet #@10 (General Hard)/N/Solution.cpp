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
	There are 3 cases:
	1. Two eyes and one body.
	2. Two eyes, one mouth, and one body.
	3. One eye, one mouth, and one body.
	*/
	long long int eyes, mouths, bodies;
	cin >> eyes >> mouths >> bodies;
	if (eyes == 0 || bodies == 0)
		cout << 0; // Because eyes and bodies are needed in ALL cases

	else if (mouths < bodies && mouths < eyes) // 90 24 89
		cout << (mouths + min(((eyes - mouths) / 2), bodies - mouths));
	// Make as many as possible of case 3 and 1 (respectively) until either eyes or bodies are totally consumed (either of them is zero)

	// 12 25 13
	else //(mouths >= bodies || mouths >= eyes)
		cout << min(eyes, bodies);
	// make as many as possible of case 3 until either eyes or bodies are totally consumed (either of them is zero)
	// and after that, we won't be able to make katryoshkas anymore Because eyes and bodies are needed in ALL cases
	return 0;
}