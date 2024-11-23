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

struct Node
{
	ll Value;
	Node *LeftChild, *RightChild; // Pointers to left child and right child

	Node(const ll &val = 0)
	{
		Value = val;
		LeftChild = nullptr;
		RightChild = nullptr;
	}

	void createChildren() // Construct Childs
	{
		if (LeftChild == nullptr)
			LeftChild = new Node();
		if (RightChild == nullptr)
			RightChild = new Node();
	}
};

struct dynamicSegmentTree
{
#define mid ((left + right) >> 1)
private:
	ll N;
	Node *root;
	ll merge(const ll &leftNode, const ll &rightNode)
	{
		ll res;
		res = (leftNode + rightNode);
		return res;
	}
	void update(int left, int right, Node *Current, int idx, const ll &newValue)
	{
		// idx is not in range [left, right]
		if (left > idx || right < idx)
			return;

		// Current is the Node that manage only ith element
		if (left == right)
		{
			Current->Value += newValue;
			return;
		}

		Current->createChildren();
		update(left, mid, Current->LeftChild, idx, newValue);
		update(mid + 1, right, Current->RightChild, idx, newValue);
		Current->Value = merge(Current->LeftChild->Value, Current->RightChild->Value);
	}
	ll query(int left, int right, Node *&Current, int leftQuery, int rightQuery)
	{
		// [left, right] doesn't intersect with [leftQuery, rightQuery]
		if (Current == nullptr || left > rightQuery || right < leftQuery)
			return 0;

		// [left, curR] is inside [leftQuery, rightQuery]
		if (leftQuery <= left && right <= rightQuery)
			return Current->Value;

		ll leftSegment{}, rightSegment{};
		leftSegment = query(left, mid, Current->LeftChild, leftQuery, rightQuery);
		rightSegment = query(mid + 1, right, Current->RightChild, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	dynamicSegmentTree()
	{
		root = new Node();
		N = 2e6;
	}
	void update(int idx, const ll &val)
	{
		update(0, N, root, idx, val);
	}
	ll query(int left, int right)
	{
		ll ans = query(0, N, root, left, right);
		return ans;
	}
#undef mid
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		ll n, q;
		cin >> n >> q;
		vector<ll> arr(n), vc;
		for (ll i{}; i < n; i++)
			cin >> arr[i], vc.push_back(arr[i]);

		dynamicSegmentTree segTree;

		vector<tuple<int, int, int>> query(q);
		for (auto &[type, L, R] : query)
		{
			char x;
			cin >> x;
			if (x == '!')
			{
				type = 1;
				auto &idx = L;
				auto &val = R;
				cin >> idx >> val;
				idx--;

				vc.push_back(val);
			}
			else
			{
				type = 2;
				cin >> L >> R;
				vc.push_back(L);
				vc.push_back(R);
			}
		}
		compressedRange comp(vc);
		for (int i{}; i < n; i++)
			arr[i] = comp.index(arr[i]), segTree.update(arr[i], 1);

		for (auto &[type, L, R] : query)
		{
			R = comp.index(R);
			if (type == 1)
			{
				auto &idx = L;
				auto &val = R;
				segTree.update(arr[idx], -1);
				segTree.update(val, 1);
				arr[idx] = val;
			}
			else
			{
				L = comp.index(L);
				cout << segTree.query(L, R) << '\n';
			}
		}
		return 0;
	}
}