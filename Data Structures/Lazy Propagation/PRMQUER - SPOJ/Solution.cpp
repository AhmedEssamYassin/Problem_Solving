#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bitset<10000001> isPrime;

void Sieve_Of_Eratosthenes(ll N)
{
	isPrime.set(); // Initially Assuming all numbers to be primes

	isPrime[0] = isPrime[1] = 0; // 0 and 1 are NOT primes

	for (ll i{2}; i * i <= N; i++)
	{
		if (isPrime[i])
		{
			for (ll j = i * i; j <= N; j += i)
				isPrime[j] = 0; // Crossing out all the multiples of prime numbers
		}
	}
}

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll countPrimes{};
		ll value{};
		Node() {}
		Node(const ll &N)
		{
			if (N <= 10000000 && N >= 0)
				countPrimes = isPrime[N];
			else
				countPrimes = 0;
			value = N;
		}
	};
	struct LazyNode
	{
		ll value{};
		LazyNode() {}
		LazyNode(const ll &N) : value(N) {}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.countPrimes = (leftNode.countPrimes + rightNode.countPrimes);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
			return;
		}
		// Recursively build the left child
		build(left, mid, L, arr);
		// Recursively build the right child
		build(mid + 1, right, R, arr);
		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}
	void push(int left, int right, int node)
	{
		// Propagate the value
		if (lazy[node].value == -1)
			return;

		if (lazy[node].value <= 10000000)
			seg[node].countPrimes = (right - left + 1) * isPrime[lazy[node].value];
		else
			seg[node].countPrimes = 0;
		seg[node].value = (right - left + 1) * lazy[node].value;
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L] = lazy[node];
			// Update the lazy values for the right child
			lazy[R] = lazy[node];
		}
		// Reset the lazy value
		lazy[node] = -1;
	}
	void updateRange(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			lazy[node] = val;
			// Apply the update immediately
			push(left, right, node);
			return;
		}
		// Recursively update the left child
		updateRange(left, mid, L, leftQuery, rightQuery, val);
		// Recursively update the right child
		updateRange(mid + 1, right, R, leftQuery, rightQuery, val);
		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}
	void updatePoint(int left, int right, int node, int idx, const ll &val)
	{
		push(left, right, node);
		if (idx > right || idx < left)
			return;
		// If the range matches the segment
		if (left == right)
		{
			// Update the lazy value
			seg[node].value += val;
			if (seg[node].value <= 10000000)
				seg[node].countPrimes = isPrime[seg[node].value];
			else
				seg[node].countPrimes = 0;
			return;
		}
		// Recursively update the left child
		updatePoint(left, mid, L, idx, val);
		// Recursively update the right child
		updatePoint(mid + 1, right, R, idx, val);
		// Merge the children values
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
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		lazy = vector<LazyNode>(2 * size, -1);
		build(0, size - 1, 0, arr);
	}
	void updateRange(int left, int right, const ll &val)
	{
		updateRange(0, size - 1, 0, left, right, val);
	}
	void updatePoint(int idx, const ll &val)
	{
		updatePoint(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.countPrimes;
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
	Sieve_Of_Eratosthenes(10000000);
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		segmentTree segTree(vc);
		while (Q--)
		{
			char query;
			ll L, R, V, a;
			cin >> query;
			if (query == 'A')
			{
				cin >> V >> L;
				--L;
				segTree.updatePoint(L, V);
			}
			else if (query == 'R')
			{
				cin >> a >> L >> R;
				--L, --R;
				segTree.updateRange(L, R, a);
			}
			else
			{
				cin >> L >> R;
				--L, --R;
				cout << segTree.query(L, R) << endl;
			}
		}
	}
	return 0;
}
