#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Matrix
{
	ll row, col;
	vector<vector<ll>> a;
	// Empty constructor
	Matrix() {}
	Matrix(const size_t &r, const size_t &c)
	{
		row = r;
		col = c;
		a.resize(r, vector<ll>(c, 0));
	}
	// Deep Copy constructor
	Matrix(const Matrix &other)
	{
		for (int i{}; i < row; i++)
		{
			for (int j{}; j < col; j++)
				a[i][j] = other.a[i][j];
		}
	}
	// Overloading the multiplication operator
	Matrix operator*(const Matrix &other) const
	{
		Matrix product(row, other.col);
		for (int i{}; i < row; i++)
		{
			for (int j{}; j < col; j++)
			{
				for (int k{}; k < other.col; k++)
					product.a[i][k] += (a[i][j] * other.a[j][k]);
			}
		}
		return product;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, X;
	// cin >> t;
	while (t--)
	{
		ll r1, c1, r2, c2;
		cin >> r1 >> c1;
		Matrix MatA(r1, c1);
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
				cin >> MatA.a[i][j];
		}
		cin >> r2 >> c2;
		Matrix MatB(r2, c2);
		for (int i = 0; i < r2; i++)
		{
			for (int j = 0; j < c2; j++)
				cin >> MatB.a[i][j];
		}
		Matrix res(MatA * MatB);
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
				cout << res.a[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}