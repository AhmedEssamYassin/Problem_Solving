#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll sum;
		ll GCD;
		Node() {}
		Node(const ll &N) : sum(N), GCD(N) {}
	};
	int size;
	vector<ll> mult, div;
	vector<Node> seg;
	void reduce(ll node)
	{
		ll g = gcd(mult[node], div[node]);
		mult[node] /= g;
		div[node] /= g;
	}
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.sum = (leftNode.sum + rightNode.sum);
		res.GCD = gcd(leftNode.GCD, rightNode.GCD);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
		}
		else
		{
			// Recursively build the left child
			build(left, mid, L, arr);
			// Recursively build the right child
			build(mid + 1, right, R, arr);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}
	void push(int left, int right, int node)
	{
		if (mult[node] == 1 && div[node] == 1)
			return;
		// Propagate the value
		reduce(node);
		seg[node].sum = (seg[node].sum * mult[node] / div[node]);
		seg[node].GCD = (seg[node].GCD * mult[node] / div[node]);
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			mult[L] *= mult[node];
			div[L] *= div[node];
			// Update the lazy values for the right child
			mult[R] *= mult[node];
			div[R] *= div[node];
			reduce(L);
			reduce(R);
		}
		// Reset the mult,div value
		mult[node] = 1;
		div[node] = 1;
	}

	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			div[node] *= val;

			// Apply the update immediately
			push(left, right, node);
		}
		else
		{
			// Recursively update the left child
			update(left, mid, L, leftQuery, rightQuery, val);
			// Recursively update the right child
			update(mid + 1, right, R, leftQuery, rightQuery, val);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}

	void undoUpdate(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			mult[node] *= val;

			// Apply the update immediately
			push(left, right, node);
		}
		else
		{
			// Recursively update the left child
			undoUpdate(left, mid, L, leftQuery, rightQuery, val);
			// Recursively update the right child
			undoUpdate(mid + 1, right, R, leftQuery, rightQuery, val);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}

	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Apply the pending updates if any
		push(left, right, node);
		// If the range is invalid, return a value that does NOT to affect other queries
		if (left > rightQuery || right < leftQuery)
			return 0;

		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		Node getLeftQuery = query(left, mid, L, leftQuery, rightQuery);
		Node getRightQuery = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(getLeftQuery, getRightQuery);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		mult = vector<ll>(2 * size, 1);
		div = vector<ll>(2 * size, 1);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val, int type)
	{
		if (type == 1)
			update(0, size - 1, 0, left, right, val);
		else
			undoUpdate(0, size - 1, 0, left, right, val);
	}
	Node query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans;
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
	int t = 1;
	ll N, Q;
	cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		segmentTree segTree(a);
		stack<tuple<ll, ll, ll>> updates;
		while (Q--)
		{
			ll query, L, R;
			cin >> query;
			if (query == 1)
			{
				cin >> L >> R;
				L--, R--;
				ll x = segTree.query(L, R).GCD;
				segTree.update(L, R, x, 1);
				updates.push({L, R, x});
			}
			else if (query == 2)
			{
				cin >> L >> R;
				L--, R--;
				cout << segTree.query(L, R).sum << endl;
			}
			else
			{
				const auto &[L, R, x] = updates.top();
				segTree.update(L, R, x, 2);
				updates.pop();
			}
		}
	}
	return 0;
}