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
	- d1 is the length of the path connecting Patrick's house and the first shop.
	- d2 is the length of the path connecting Patrick's house and the second shop.
	- d3 is the length of the path connecting both shops.
	To find the minimum distance that Patrick will have to walk in order to visit both shops and return to his house:
	First, consider the positions of the House, Shop_1 and Shop_2,
	Shop_1	House	Shop_2
	We need to know the minimum distance between these 4 choices:
	1. Walk d1 to reach Shop_1 then walk d1 again to reach House then walk d2 to reach Shop_2 and then walk d2 again to reach House,
	i.e. walk (2 * d1 + 2 * d2) = 2 * (d1 + d2)

	2. Walk d1 to reach Shop_1 then walk d3 to reach Shop_2 and then walk d2 to reach House, i.e. walk (d1 + d3 + d2)
	(Or walk d2 then d3 then d1 but it's the same as the second choice because addition is commutative)
	i.e. walk (d1 + d3 + d2) or (d2 + d3 + d1)

	3. Walk d1 to reach Shop_1 then walk d3 to reach Shop_2 and then walk d3 again to reach Shop_1 then walk d1 to reach House,
	i.e. walk (d1 + 2 * d3 + d1)

	4. Walk d2 to reach Shop_2 then walk d3 to reach Shop_1 and then walk d3 again to reach Shop_2 then walk d2 to reach House,
	i.e. walk (d2 + 2 * d3 + d2)

	*/
	ll d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	ll Choice_1 = (2 * d1 + 2 * d2);
	ll Choice_2 = (d1 + d3 + d2);
	ll Choice_3 = (d1 + 2 * d3 + d1);
	ll Choice_4 = (d2 + 2 * d3 + d2);

	cout << min({Choice_1, Choice_2, Choice_3, Choice_4});

	return 0;
}