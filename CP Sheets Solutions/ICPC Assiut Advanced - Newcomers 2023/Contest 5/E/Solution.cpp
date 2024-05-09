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
	We need to notice a few things.

	1. It's always possible to make the string a palindrome.

	2. It's enough to make one half of the string equal to the other half.

	3. We have to make every element equal to it's reflection. That is, make Input[i] = Input[N - i - 1]

	4. The number of vertical moves to make Input[i] and Input[N - i - 1] equal is min(Input[i] - Input[N - i - 1], 26 - Input[i] + Input[N - i - 1]}
	So, we go over every pair of elements that is not equal and calculate the vertical moves required to make them equal.

	5. Calculate the leftmost and rightmost position of the cursor in the first half that is NOT equal to it's reflection.
	   i.e., The first and last position of mismatch
	And then horizontal moves is whichever is minimum - (Cursor -> Leftmost -> Rightmost or Cursor -> Rightmost -> Leftmost)
	*/

	int N;
	string Input;
	int Starting_pos = 1; // p
	cin >> N;
	// cin >> Starting_pos;
	cin >> Input;
	if (Starting_pos >= N / 2)
	{
		reverse(Input.begin(), Input.end());
		Starting_pos = N - Starting_pos + 1;
	}

	Starting_pos--; // To make it 0-based
	int Move_cnt{};
	int L = -1, R = -1;
	for (int i = 0; i < N / 2; i++) // The middle character does NOT need to be changed, so it's enough to move until N/2
	{
		// Moving UP if Input[i] < Input[N - i - 1] ,, **c***k**
		// Moving DOWN if Input[i] > Input[N - i - 1] ,, **k***c**
		int Choice_1 = abs(Input[i] - Input[N - i - 1]);

		// Moving DOWN if Input[i] < Input[N - i - 1] ,, **c***k**
		// Moving UP if Input[i] > Input[N - i - 1] ,, **k***c**
		int Choice_2 = 26 - abs(Input[i] - Input[N - i - 1]);

		Move_cnt += min(Choice_1, Choice_2);

		if (Input[i] != Input[N - i - 1])
		{
			if (L == -1) // Didn't move yet
				L = i;	 // Stores the position of the First character to mismatch

			R = i; // Stores the position of the Last character to mismatch
		}
	}
	if (R == -1) // NO character mismatch, So NO moves are required
		return cout << 0, 0;

	/*
	Assuming that cursor's position is in the first half of string (i.e 1 <= p <= N / 2)
	(if it's NOT, just reverse the string, and change p to N - p + 1, then the answer will not change).
	*/

	if (Starting_pos <= L) //**p**L*****R*********
	{
		Move_cnt += R - Starting_pos;
	}
	else if (Starting_pos >= R) //****L*****R**p*******
	{
		Move_cnt += Starting_pos - L;
	}
	else //****L**p***R*********
	{
		int Choice_1 = Starting_pos - L; // Move to L first
		int Choice_2 = R - Starting_pos; // Move to R first
		Move_cnt += (R - L) + min(Choice_1, Choice_2);
	}
	cout << Move_cnt;

	return 0;
}