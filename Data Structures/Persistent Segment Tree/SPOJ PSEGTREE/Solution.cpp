#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

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

	Node(Node *l, Node *r, const ll &val = 0)
	{
		LeftChild = l;
		RightChild = r;
		Value = val;
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
Node *Versions[100001]; // To maintain versions of the segment tree

#define mid ((left + right) >> 1)
ll N = 100001;
Node *merge(Node *leftNode, Node *rightNode, bool in_place = 0, Node *Current = nullptr) // In_place for update and insert
{
	ll res = ((leftNode == nullptr ? 0 : leftNode->Value) + (rightNode == nullptr ? 0 : rightNode->Value));
	if (not in_place)
		return new Node(res);
	else
	{
		Current->Value = res;
		return Current;
	}
}

Node *insert(Node *node, int left, int right, int idx, int val) // Update for a single version
{
	if (left <= idx && right >= idx)
	{
		if (node == nullptr)
			node = new Node();

		if (left == right)
			return new Node(node->LeftChild, node->RightChild, node->Value + val);

		Node *goLeft = insert(node->LeftChild, left, mid, idx, val);
		Node *goRight = insert(node->RightChild, mid + 1, right, idx, val);
		Node *res = new Node(goLeft, goRight);
		return merge(goLeft, goRight, 1, res);
	}
	return node;
}

Node *query(Node *Current, int left, int right, int leftQuery, int rightQuery)
{
	// [left, right] doesn't intersect with [leftQuery, rightQuery]
	if (Current == nullptr || left > rightQuery || right < leftQuery)
		return 0;

	// [left, curR] is inside [leftQuery, rightQuery]
	if (leftQuery <= left && right <= rightQuery)
		return Current;

	Node *leftSegment = query(Current->LeftChild, left, mid, leftQuery, rightQuery);
	Node *rightSegment = query(Current->RightChild, mid + 1, right, leftQuery, rightQuery);
	return merge(leftSegment, rightSegment);
}

// Interface

Node *insert(Node *Current, int idx, int val)
{
	return insert(Current, 1, N, idx, val);
}

ll query(Node *Current, int left, int right)
{
	Node *ans = query(Current, 1, N, left, right);
	return ans->Value;
}
#undef mid

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
		Versions[0] = new Node(0);
		for (int i{1}; i <= N; i++)
		{
			ll x;
			cin >> x;
			Versions[0] = insert(Versions[0], i, x);
		}
		cin >> Q;
		int k = 1;
		while (Q--)
		{
			ll q, idx, pos, val, L, R;
			cin >> q;
			if (q == 1)
			{
				cin >> idx >> pos >> val;
				Versions[k++] = insert(Versions[idx], pos, val);
			}
			else
			{
				cin >> idx >> L >> R;
				cout << query(Versions[idx], L, R) << endl;
			}
		}
	}
	return 0;
}