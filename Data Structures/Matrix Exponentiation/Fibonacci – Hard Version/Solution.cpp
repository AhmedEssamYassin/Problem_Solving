#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int MOD = 1000000007;
struct Matrix
{
	ll a[2][2] = {{0, 0}, {0, 0}};
	// Empty constructor
	Matrix() {}
	/*Matrix(ll a00, ll a01, ll a10, ll a11)
	{
		a[0][0] = a00;
		a[0][1] = a01;
		a[1][0] = a10;
		a[1][1] = a11;
	}*/

	// Deep Copy constructor
	Matrix(const Matrix &other)
	{
		a[0][0] = other.a[0][0];
		a[0][1] = other.a[0][1];
		a[1][0] = other.a[1][0];
		a[1][1] = other.a[1][1];
	}
	// Overloading the multiplication operator
	Matrix operator*(const Matrix &other) const
	{
		Matrix product;
		for (int i{}; i < 2; i++)
		{
			for (int j{}; j < 2; j++)
			{
				for (int k{}; k < 2; k++)
				{
					product.a[i][k] += (a[i][j] * other.a[j][k]);
					product.a[i][k] %= MOD;
				}
			}
		}
		return product;
	}
};

Matrix Matrix_Bin_Exp(Matrix a, ll k)
{
	Matrix product;
	// Constructing the identity matrix {{1, 0}, {0, 1}}
	for (int i{}; i < 2; i++)
		product.a[i][i] = 1;

	while (k)
	{
		if (k & 1)
			product = product * a;

		a = a * a;
		k >>= 1;
	}
	return product;
}
ll Nth_Fib(ll power)
{
	Matrix F;
	F.a[0][0] = 0;
	F.a[0][1] = 1;
	F.a[1][0] = 1;
	F.a[1][1] = 1;
	Matrix ans = Matrix_Bin_Exp(F, power);
	return ans.a[1][0];
}

ll fibSummation(ll N)
{
	return Nth_Fib(N + 2) - 2;
}

ll add(ll a, ll b)
{
	ll x = a + b;
	if (x >= MOD)
		x -= MOD;
	if (x < MOD)
		x += MOD;
	return x;
}

ll sub(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll L, R;
	cin >> t;
	while (t--)
	{
		cin >> L >> R;
		cout << sub(fibSummation(R), fibSummation(L - 1)) << endl;
	}
	return 0;
}