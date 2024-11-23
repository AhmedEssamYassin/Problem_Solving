#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int mod = 1000000007;
class compressedRange
{
private:
	vector<ll> init;
	void compress(vector<ll> &vec)
	{
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

public:
	compressedRange(vector<ll> vec)
	{
		init = vec;
		compress(init);
	}
	int index(ll val)
	{
		return lower_bound(init.begin(), init.end(), val) - init.begin();
	}
	ll initVal(int idx)
	{
		return init[idx];
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
		ll sum;

		// Constructors
		Node() {}
		Node(ll val) : sum(val) {}
		Node operator+(const Node &other)
		{
			sum += other.sum;
			return *this;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.sum = leftNode.sum + rightNode.sum;
		res.sum %= mod;
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
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
	void update(int left, int right, int node, int idx, ll val)
	{
		if (left == right)
		{
			seg[node].sum += val;
			seg[node].sum %= mod;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, val);
		else
			update(mid + 1, right, R, idx, val);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Out of range
		if (right < leftQuery || left > rightQuery)
			return Node(0); // A value that doesn't affect the answer

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
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(0));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, ll val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.sum;
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
	ll N;
	cin >> N;
	vector<ll> vc(N), pref(N);
	for (int i{}; i < N; i++)
		cin >> vc[i];

	pref[0] = vc[0];
	for (int i{1}; i < N; i++)
		pref[i] = pref[i - 1] + vc[i];
	// The problem is that negative numbers cannot be treated as indices
	compressedRange comp(pref);
	segmentTree freqTree(vector<ll>(N + 1, 0));
	segmentTree sumTree(vector<ll>(N + 1, 0));

	ll sum{};
	for (int i{}; i < N; i++)
	{
		if (pref[i] > 0)
			sum = (sum % mod + pref[i] % mod) % mod;

		int idx = comp.index(pref[i]);
		ll freq = freqTree.query(0, idx);
		ll cur = sumTree.query(0, idx);
		sum = (sum % mod + ((freq % mod * pref[i] % mod) % mod - cur + mod) % mod) % mod;
		sumTree.update(idx, pref[i]);
		freqTree.update(idx, 1);
	}
	cout << sum;
	return 0;
}