#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int MOD;
struct Matrix
{
	ll a[2][2] = {{0, 0}, {0, 0}};
	// Empty constructor
	Matrix() {}
	Matrix(ll a00, ll a01, ll a10, ll a11)
	{
		a[0][0] = a00;
		a[0][1] = a01;
		a[1][0] = a10;
		a[1][1] = a11;
	}

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
		Matrix product(0, 0, 0, 0);
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

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		Matrix matrix;
		// Constructors
		Node()
		{
			matrix.a[0][0] = 1;
			matrix.a[0][1] = 0;
			matrix.a[1][0] = 0;
			matrix.a[1][1] = 1;
		}
		Node(const Matrix &other) : matrix(other) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.matrix = (leftNode.matrix * rightNode.matrix);
		return res;
	}
	template <typename T>
	void build(int left, int right, int node, vector<T> &arr)
	{
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = Node(arr[left]);
			return;
		}

		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, const Matrix &other)
	{
		if (left == right)
		{
			seg[node].matrix = other;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, other);
		else
			update(mid + 1, right, R, idx, other);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Out of range
		if (right < leftQuery || left > rightQuery)
			return Node(Matrix(1, 0, 0, 1)); // Identity Matrix
		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];
		else // ONLY a part of this segment belongs to the query
		{
			Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
			Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
			return merge(leftSegment, rightSegment);
		}
	}

public:
	template <typename T>
	segmentTree(vector<T> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(Matrix()));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const Matrix &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	Matrix query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.matrix;
	}

#undef L
#undef R
#undef mid
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int N, M, L, R;
	cin >> MOD >> N >> M;
	vector<Matrix> vc(N);
	for (int i{}; i < N; i++)
	{
		cin >> vc[i].a[0][0];
		cin >> vc[i].a[0][1];
		cin >> vc[i].a[1][0];
		cin >> vc[i].a[1][1];
	}
	segmentTree segTree(vc);
	while (M--)
	{
		cin >> L >> R;
		L--, R--; // To be 0-based
		Matrix ans = segTree.query(L, R);
		cout << ans.a[0][0] << " " << ans.a[0][1] << endl;
		cout << ans.a[1][0] << " " << ans.a[1][1] << endl;
		cout << endl;
	}
	return 0;
}