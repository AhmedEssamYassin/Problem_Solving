#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

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
	compressedRange(vector<ll> &vec)
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
		Node(ll val)
		{
			sum = val;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, Node &rightNode)
	{
		Node res;
		res.sum = (leftNode.sum + rightNode.sum);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		if (left == right) // Leaf Node (single element)
		{
			if (left < arr.size()) // Making sure we are inside the boundaries of the array
				seg[node] = arr[left];
			return;
		}
		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, const ll &val)
	{
		if (left == right)
		{
			seg[node] = val;
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
			return 0; // A value that doesn't affect the query

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
		seg = vector<Node>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
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
	int t = 1;
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		compressedRange comp(vc);
		vector<vector<int>> ind(N + 1); // indices for each compressed value
		for (int i{}; i < N; i++)
			ind[comp.index(vc[i])].push_back(i);

		segmentTree segTree(vector<ll>(N + 1, 0));
		cin >> Q;
		vector<pair<pair<int, int>, pair<int, int>>> queries;
		for (int ind{}; ind < Q; ind++)
		{
			ll i, j, k;
			cin >> i >> j >> k;
			i--, j--;
			queries.push_back({{k, ind}, {i, j}});
		}

		sort(queries.begin(), queries.end()); // In ascending order w.r.t k
		vector<ll> ans(Q);
		ll mx = -1;
		for (int i{}, j{}; i < Q; i++)
		{
			auto &[query, interval] = queries[i];
			auto &[k, pos] = query;
			auto &[L, R] = interval;
			int idx = comp.index(k);
			if (comp.initVal(idx) > k)
				idx--;
			while (mx <= idx)
			{
				if (mx >= 0)
				{
					for (const int &x : ind[mx])
						segTree.update(x, 1);
				}
				mx++;
			}
			ans[pos] = R - L + 1 - segTree.query(L, R);
		}
		for (const ll &query : ans)
			cout << query << endl;
	}
	return 0;
}
