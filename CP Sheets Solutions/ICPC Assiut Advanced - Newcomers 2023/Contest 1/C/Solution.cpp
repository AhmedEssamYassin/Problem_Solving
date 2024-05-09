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
	string Ans = "";

	/*
	Each egg should be painted one color out of 7: R: Red, O: Orange, Y: Yellow, G: Green, B: Blue, I: Indigo or V: Violet.
	Also, the following conditions should be satisfied:
	1. Each of the seven colors should be used to paint AT LEAST one egg.
	2. Any four eggs lying sequentially should be painted different colors.

	Let there be 1, 2, 3,..., N eggs,
	The eggs are put in a circle.
	So, the last 3 eggs will always be adjacent to the 1st egg.
	i.e. There are 3 groups of "four eggs lying sequentially" at the end that need to be handled:
	{N-2, N-1, N, 1}, {N-1, N, 1, 2}, {N, 1, 2, 3}
	- For ALL complete 7-egg cycles (N / 7), We will choose the set of colors {'R','O','Y','G','B','I','V'} respectively
	- For the rest of the eggs (N % 7), we will always choose from the set of colors {'G','B','I','V'} respectively
	in order to prevent the repetition of any color in the last three groups:
	{N-2, N-1, N, 1}, {N-1, N, 1, 2}, {N, 1, 2, 3} as well as NOT repeating a color with the previous eggs
	*/
	char Color_Set_1[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
	for (int i{1}, picker{}; i <= N / 7 * 7; i++)
	{
		Ans += Color_Set_1[picker++];
		picker %= 7; // To make the picker "Cyclic", i.e. becomes 0 when reaching 7. That means it's in the range [0,6] which is the indices of the Color_Set_1[]
	}

	char Color_Set_2[] = {'G', 'B', 'I', 'V'};
	for (int i{1}, picker{}; i <= N % 7; i++)
	{
		Ans += Color_Set_2[picker++];
		picker %= 4; // To make the picker "Cyclic", i.e. becomes 0 when reaching 4. That means it's in the range [0, 3] which is the indices of the Color_Set_2[]
	}
	cout << Ans;

	return 0;
}