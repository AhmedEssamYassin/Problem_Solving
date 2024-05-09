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

	int Coin_n;
	int Number_of_coins{}, Sum{};
	/*
	His good friend told him that he has an infinite number of coins of values (25,10,5 and 1)
	and that he doesn't mind exchanging some of them with one Coin_n

	Find the minimum number of coins he needs to take in exchange for the Coin_n

	In order to get the minimum number of coins, we must take as many as possible of greater coins first
	because greater coins will yield big values with small number of coins
	*/
	cin >> Coin_n;
	if (Coin_n == 10) // If Coin_n is 10, he does NOT need to exchange anything
		return cout << 0, 0;

	Number_of_coins += Coin_n / 25; // Take as many as possible of coin with value 25

	Coin_n %= 25; // what remains of Coin_n after subtracting all 25's

	Number_of_coins += Coin_n / 10; // Take as many as possible of coin with value 10

	Coin_n %= 10; // what remains of Coin_n after subtracting all 10's

	Number_of_coins += Coin_n / 5; // Take as many as possible of coin with value 5

	Coin_n %= 5; // what remains of Coin_n after subtracting all 5's

	Number_of_coins += Coin_n / 1; // Take as many as possible of coin with value 1
	cout << Number_of_coins;

	return 0;
}