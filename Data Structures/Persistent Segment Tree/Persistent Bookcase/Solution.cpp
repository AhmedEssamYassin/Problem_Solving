#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll m;
struct Node
{
	ll Value;
	bitset<1001> bitmask;
	Node *LeftChild, *RightChild; // Pointers to left child and right child

	Node(const ll &val = 0)
	{
		Value = val;
		LeftChild = nullptr;
		RightChild = nullptr;
	}
	Node(Node *l, Node *r)
	{
		LeftChild = l;
		RightChild = r;
		Value = 0;
	}
	Node(Node *l, Node *r, const bitset<1001> &b, const ll &val = 0)
	{
		LeftChild = l;
		RightChild = r;
		Value = val;
		bitmask = b;
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
ll N = 1001;
Node *merge(Node *leftNode, Node *rightNode, bool in_place = 0, Node *Current = nullptr) // In_place for update and insert
{
	ll res = ((leftNode == nullptr ? 0 : leftNode->Value) + (rightNode == nullptr ? 0 : rightNode->Value));
	bitset<1001> b;
	if (leftNode != nullptr && rightNode != nullptr)
		b = (leftNode->bitmask | rightNode->bitmask);

	else if (leftNode != nullptr)
		b = leftNode->bitmask;
	else if (rightNode != nullptr)
		b = rightNode->bitmask;

	if (not in_place)
		return new Node(nullptr, nullptr, b, res);
	else
	{
		Current->Value = res;
		Current->bitmask = b;
		return Current;
	}
}

Node *insert(Node *node, int left, int right, int i, int j, int state) // Update for a single version
{
	if (left <= i && right >= i)
	{
		if (node == nullptr)
			node = new Node();

		if (left == right)
		{
			bitset<1001> b = node->bitmask;
			if (state != -1)
			{
				b.set(j, (state == 1));
				int sum{};
				for (int k{1}; k <= m; k++)
					sum += b[k];

				return new Node(node->LeftChild, node->RightChild, b, sum);
			}
			b.flip();
			int sum{};
			for (int i{1}; i <= m; i++)
				sum += b[i];

			return new Node(node->LeftChild, node->RightChild, b, sum);
		}

		Node *goLeft = insert(node->LeftChild, left, mid, i, j, state);
		Node *goRight = insert(node->RightChild, mid + 1, right, i, j, state);
		Node *res = new Node(goLeft, goRight);
		return merge(goLeft, goRight, 1, res);
	}
	return node;
}

ll query(Node *Current, int left, int right, int leftQuery, int rightQuery)
{
	// [left, right] doesn't intersect with [leftQuery, rightQuery]
	if (Current == nullptr || left > rightQuery || right < leftQuery)
		return 0;

	// [left, curR] is inside [leftQuery, rightQuery]
	if (leftQuery <= left && right <= rightQuery)
		return Current->Value;

	ll leftSegment = query(Current->LeftChild, left, mid, leftQuery, rightQuery);
	ll rightSegment = query(Current->RightChild, mid + 1, right, leftQuery, rightQuery);
	return (leftSegment + rightSegment);
}

// Interface

Node *insert(Node *Current, int i, int j, int state)
{
	return insert(Current, 1, N, i, j, state);
}

ll query(Node *Current, int left, int right)
{
	ll ans = query(Current, 1, N, left, right);
	return ans;
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
	ll N, M, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> Q;
		m = M;
		Versions[0] = new Node(0);
		for (int q{1}; q <= Q; q++)
		{
			ll type, i, j, k;
			cin >> type;
			if (type == 1)
			{
				cin >> i >> j;
				Versions[q] = insert(Versions[q - 1], i, j, 1);
			}
			else if (type == 2)
			{
				cin >> i >> j;
				Versions[q] = insert(Versions[q - 1], i, j, 0);
			}
			else if (type == 3)
			{
				cin >> i;
				Versions[q] = insert(Versions[q - 1], i, j, -1);
			}
			else
			{
				cin >> k;
				Versions[q] = Versions[k];
			}
			cout << query(Versions[q], 1, 1001) << endl;
		}
	}
	return 0;
}