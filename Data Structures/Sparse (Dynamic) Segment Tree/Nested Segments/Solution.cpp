#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct dynamicSegmentTree
{
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll Value;
		Node *LeftChild, *RightChild; // Pointers to left child and right child

		Node() // Constructor
		{
			Value = 0;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
		Node(const ll &val)
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
		~Node() // Destructor. Notice the "~" character before the struct name.
		{
			delete LeftChild;
			delete RightChild;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};
	ll N;
	Node *root;
	ll merge(const ll &leftNode, const ll &rightNode)
	{
		ll res;
		res = (leftNode + rightNode);
		return res;
	}
	void update(ll left, ll right, Node *Current, ll idx, const ll &newValue)
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
	ll query(ll left, ll right, Node *Current, ll leftQuery, ll rightQuery)
	{
		// [left, right] doesn't intersect with [leftQuery, rightQuery]
		if (left > rightQuery || right < leftQuery)
			return 0;

		// [left, curR] is inside [leftQuery, rightQuery]
		if (leftQuery <= left && right <= rightQuery)
			return Current->Value;

		Current->createChildren();
		ll leftSegment = query(left, mid, Current->LeftChild, leftQuery, rightQuery);
		ll rightSegment = query(mid + 1, right, Current->RightChild, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	dynamicSegmentTree()
	{
		root = new Node();
		N = 2e9 + 2;
	}
	void update(ll idx, const ll &val)
	{
		update(0, N, root, idx, val);
	}
	ll query(ll left, ll right)
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<tuple<ll, ll, int>> intervals(N);
		vector<ll> Rs;
		dynamicSegmentTree segTree;

		// Instead of Coordinate compression
		ll minValue = LLONG_MAX;
		auto giveOffset = [&](ll x)
		{
			return x + abs(minValue);
		};
		int pos = 0;
		for (auto &[L, R, idx] : intervals)
		{
			cin >> L >> R;
			idx = pos++;
			minValue = min(minValue, L);
			minValue = min(minValue, R);
		}

		for (auto &[L, R, idx] : intervals)
		{
			L = giveOffset(L);
			R = giveOffset(R);
		}
		map<ll, ll> ans;
		sort(intervals.begin(), intervals.end()); // Sorting on basis of `L`
		for (int i = N - 1; i >= 0; i--)
		{
			auto &[L, R, idx] = intervals[i];
			ans[idx] = segTree.query(0, R);
			segTree.update(R, 1);
		}
		for (const auto &[idx, cnt] : ans)
			cout << cnt << endl;
	}
	return 0;
}