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
	int *arr_1 = new int[N];
	int *arr_2 = new int[N];
	for (int i{}; i < N; i++)
	{
		cin >> arr_1[i];
		arr_2[i] = arr_1[i];
	}

	/*
	An array of N integers is alternating if each value starting from the SECOND one has different sign than the one before it.
	i.e. The FIRST element in the array is the element that determines all the signs of that alternating array
	+ - + - + - + - + ...
	- + - + - + - + - ...

	Given an array of N integers, in one move, you are allowed to choose an integer and multiply it by -1.
	Find the minimum number of moves required to convert the given array into an alternating array.

	We have ONLY two possibilities:
	1. The FIRST element is +ve
	2. The FIRST element is -ve
	we will choose the minimum number of moves required to convert the given array into an alternating array out of these two possibilities.
	*/
	int cnt_1{};

	// Leaving the FIRST element as it is (doesn't matter it's +ve or -ve)
	for (int i{1}; i < N; i++)
	{
		if (arr_1[i] * arr_1[i - 1] > 0) // If they are of the same sign (+ + or - -)
		{
			cnt_1++;
			arr_1[i] *= -1; // Changing the sign of the current element
		}
	}

	// Changing the sign of the FIRST element (+ve to -ve OR -ve to +ve)
	arr_2[0] *= -1;
	int cnt_2{1}; // Starting from 1 NOT 0 because we made a move (changed the sign of the FIRST element)
	for (int i{1}; i < N; i++)
	{
		if (arr_2[i] * arr_2[i - 1] > 0) // If they are of the same sign (+ + or - -)
		{
			cnt_2++;
			arr_2[i] *= -1; // Changing the sign of the current element
		}
	}
	cout << min(cnt_1, cnt_2);
	delete[] arr_1, arr_2;
	return 0;
}