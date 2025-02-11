#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct dynamicSegmentTree
{
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll sum;
		ll maxPrefSum;
		Node *LeftChild, *RightChild; // Pointers to left child and right child

		Node() // Constructor
		{
			sum = 0;
			maxPrefSum = 0;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
		Node(const ll &val, const ll &maxVal)
		{
			sum = val;
			maxPrefSum = maxVal;
			LeftChild = nullptr;
			RightChild = nullptr;
		}

		void createChildren(const ll &val = 0, const ll &maxVal = 0) // Construct Childs
		{
			if (LeftChild == nullptr)
				LeftChild = new Node(val, maxVal);
			if (RightChild == nullptr)
				RightChild = new Node(val, maxVal);
		}
		~Node() // Destructor. Notice the "~" character before the struct name.
		{
			delete LeftChild;
			delete RightChild;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};
	struct LazyNode
	{
		ll Value;
		LazyNode *LeftChild, *RightChild; // Pointers to left child and right child

		LazyNode() // Constructor
		{
			Value = INF;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
		LazyNode(const ll &val)
		{
			Value = val;
			LeftChild = nullptr;
			RightChild = nullptr;
		}

		void createChildren(const ll &val = INF) // Construct Childs
		{
			if (LeftChild == nullptr)
				LeftChild = new LazyNode(val);
			if (RightChild == nullptr)
				RightChild = new LazyNode(val);
		}
		~LazyNode() // Destructor. Notice the "~" character before the struct name.
		{
			delete LeftChild;
			delete RightChild;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};
	ll N;
	Node *segRoot;
	LazyNode *lazyRoot;
	void merge(Node *&segNode)
	{
		segNode->sum = (segNode->LeftChild->sum + segNode->RightChild->sum);
		segNode->maxPrefSum = max(segNode->LeftChild->maxPrefSum, segNode->LeftChild->sum + segNode->RightChild->maxPrefSum);
	}

	void push(ll left, ll right, Node *segNode, LazyNode *lazyNode)
	{
		// Propagate the value
		if (segNode == nullptr || lazyNode == nullptr || lazyNode->Value == INF)
			return;
		// (a + b + c + d + e) --> (x + x + x + x + x) --> (right - left + 1) * x
		segNode->sum = (right - left + 1) * lazyNode->Value;
		segNode->maxPrefSum = max(0LL, segNode->sum);
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			if (lazyNode->LeftChild == nullptr)
				lazyNode->LeftChild = new LazyNode(lazyNode->Value);
			else
				lazyNode->LeftChild->Value = lazyNode->Value;

			// Update the lazy values for the right child
			if (lazyNode->RightChild == nullptr)
				lazyNode->RightChild = new LazyNode(lazyNode->Value);
			else
				lazyNode->RightChild->Value = lazyNode->Value;
		}
		// Reset the lazy value
		lazyNode->Value = INF;
	}
	void update(ll left, ll right, Node *segNode, LazyNode *lazyNode, ll leftQuery, ll rightQuery, const ll &val)
	{
		push(left, right, segNode, lazyNode);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			lazyNode->Value = val;
			// Apply the update immediately
			push(left, right, segNode, lazyNode);
			return;
		}
		segNode->createChildren();
		lazyNode->createChildren(INF);
		// Recursively update the left child
		update(left, mid, segNode->LeftChild, lazyNode->LeftChild, leftQuery, rightQuery, val);
		// Recursively update the right child
		update(mid + 1, right, segNode->RightChild, lazyNode->RightChild, leftQuery, rightQuery, val);
		// Merge the children values
		merge(segNode);
	}
	ll query(ll left, ll right, Node *segNode, LazyNode *lazyNode, ll h)
	{
		// Apply the pending updates if any
		push(left, right, segNode, lazyNode);

		// If leaf node
		if (left == right)
			return left - (segNode->maxPrefSum > h);

		segNode->createChildren();
		lazyNode->createChildren(INF);

		// Apply the pending updates (if any) on the leftChild before using
		push(left, mid, segNode->LeftChild, lazyNode->LeftChild);
		if (segNode->LeftChild->maxPrefSum > h)
			return query(left, mid, segNode->LeftChild, lazyNode->LeftChild, h);
		else
			return query(mid + 1, right, segNode->RightChild, lazyNode->RightChild, h - segNode->LeftChild->sum);
	}

public:
	dynamicSegmentTree(ll rangeSize = 2e9)
	{
		segRoot = new Node();
		lazyRoot = new LazyNode(INF);
		N = rangeSize;
	}
	void update(ll left, ll right, const ll &val)
	{
		update(1, N, segRoot, lazyRoot, left, right, val);
	}
	ll query(ll h)
	{
		ll ans = query(1, N, segRoot, lazyRoot, h);
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
		char C;
		ll a, b, D, h;
		dynamicSegmentTree segTree(N);
		segTree.update(1, N, 0); // Initially, make all elements 0
		while (cin >> C)
		{
			if (C == 'E')
				return 0;
			if (C == 'I')
			{
				cin >> a >> b >> D;
				segTree.update(a, b, D);
			}
			else if (C == 'Q')
			{
				cin >> h;
				// The summation is NOT monotonic!! We cannot binary search
				cout << segTree.query(h) << endl;
			}
		}
	}
	return 0;
}