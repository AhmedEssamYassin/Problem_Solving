#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll N;
struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll ones{};
		Node() {}
		Node(const ll &N) : ones(N == 1) {}
	};
	int size;
	vector<Node> seg, lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.ones = (leftNode.ones + rightNode.ones);
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
		// Propagate the value
		if (lazy[node].ones == 1)
		{
			seg[node].ones = (right - left + 1) - seg[node].ones;
			// If the node is not a leaf
			if (left != right)
			{
				// Update the lazy values for the left child
				lazy[L].ones ^= 1;
				// Update the lazy values for the right child
				lazy[R].ones ^= 1;
			}
			// Reset the lazy value
			lazy[node] = -1;
		}
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
			lazy[node].ones ^= val;

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

	void updatePoint(int left, int right, int node, int idx, const ll &val)
	{
		if (left == right)
		{
			seg[node] = val;
			return;
		}
		if (idx <= mid)
			updatePoint(left, mid, L, idx, val);
		else
			updatePoint(mid + 1, right, R, idx, val);
		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
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

		return merge(query(left, mid, L, leftQuery, rightQuery), query(mid + 1, right, R, leftQuery, rightQuery));
	}

public:
	segmentTree(const vector<ll> &arr = vector<ll>(N, 0))
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		lazy = vector<Node>(2 * size, -1);
		// build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}

	void updatePoint(int idx, ll val)
	{
		updatePoint(0, size - 1, 0, idx, val);
	}

	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.ones;
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
	freopen("test_input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll Q;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		segmentTree arr[31];
		for (int i{}; i < N; i++)
		{
			ll x;
			cin >> x;
			int k{};
			while (x)
			{
				if (x & 1)
					arr[k].updatePoint(i, 1);
				k++, x >>= 1;
			}
		}
		cin >> Q;
		while (Q--)
		{
			ll q, L, R, b;
			cin >> q;
			if (q == 1)
			{
				cin >> L >> R;
				L--, R--;
				ll sum{};
				for (int k{}; k < 31; k++)
				{
					ll cnt = arr[k].query(L, R);
					sum += cnt * (1LL << k);
				}
				cout << sum << endl;
			}
			else
			{
				cin >> L >> R >> b;
				L--, R--;
				int k{};
				while (b)
				{
					if (b & 1)
						arr[k].update(L, R, 1);
					k++, b >>= 1;
				}
			}
		}
	}
	return 0;
}