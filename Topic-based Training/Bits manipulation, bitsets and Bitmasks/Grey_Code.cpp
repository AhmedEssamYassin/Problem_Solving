#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
/*
Gray Code:  is a binary numeral system where two successive values differ in only one bit

0000		0000	0
0001		0001	1
0010		0011	2
0011		0010	1
0100		0110	2
0101		0111	3
0110		0101	2
0111		0100	1
1000		1100	2
1001		1101	3
1010		1111	4
1011		1110	3
1100		1010	2
1101		1011	3
1110		1001	2
1111


Build it incrementally, Let's see for len = 1
0
1

Great. For len = 1 we have correct List.
For length 2, we know we need to add prefix 0 and 1 so doubling list
00
01
10
11
Great, Len = 2 also works well.

For length 3:

000
001
010
011
100
101
110
111

Failed. Note. We know 1st 4 numbers are correct. As the bits count did not change. Same for 2nd 4 numbers. All incremented 1.
Problem when moved from 4th to 5th. The point, they will always be 0111111 and 100000.
What about reversing 2nd list, so we got the biggest 111111 one beside end of 1st block 011111.

So all what we need. Given answer of list N-1. To generate N. use 0N + 1N' where N' is reverse list.
If we built the list incrementally including from N=2 we got.
0000		0000	0
0001		0001	1
0010		0011	2
0011		0010	1
0100		0110	2
0101		0111	3
0110		0101	2
0111		0100	1
1000		1100	2
1001		1101	3
1010		1111	4
1011		1110	3
1100		1010	2
1101		1011	3
1110		1001	2

By observation, in gray code, every bit is Xor of its bit and next one.

int grayCode(int i)
{
	return i ^ (i >> 1);
}

void printAllSubsetsGray(int len)
{
	for (int i = 0; i < (1 << len) - 1; ++i)
	{
		printNumber(i, len);
		cout << "\t\t";

		printNumber(grayCode(i), len);

		cout << "\t" << __builtin_popcount(grayCode(i));
		cout << "\n";
	}
}

// What about print all subsets of a GIVEN MASK. Easily recursive, let's do it iterative
// E.g. subsets of 101: 101, 100, 001, 000	-> Each one is tried 0, 1

// Let's first assume, mask was complete and we work on it reverse
void PrintAllSubsetsAllOnes(int len)
{
	int mask = (1 << len) - 1; // mask = 1111 for len = 4;

	for (int i = mask; i >= 0; i = i - 1)
		printNumber(i, len);
}

// So we decrease -1 to get next. Do u remember effect of X-1?

11111
11110
11101
11100
11011
11010
11001
11000
10111
10110
10101
10100
10011
10010
10001
10000
01111
01110
01101
01100
01011
01010
01001
01000
00111
00110
00101
00100
00011
00010
00001
00000
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	return 0;
}