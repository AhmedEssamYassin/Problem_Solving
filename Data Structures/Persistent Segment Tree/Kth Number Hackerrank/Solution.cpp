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
Node *Versions[100010]; // To maintain versions of the segment tree

#define mid ((left + right) >> 1)
ll N = 1e5 + 1;
Node *merge(Node *leftNode, Node *rightNode, bool in_place = 0, Node *Current = nullptr) // In_place for update and insert
{
	ll res = ((leftNode == nullptr ? 0 : leftNode->Value) + (rightNode == nullptr ? 0 : rightNode->Value));

	if (not in_place)
		return new Node(nullptr, nullptr, res);
	else
	{
		Current->Value = res;
		return Current;
	}
}

Node *insert(Node *node, int left, int right, int i, ll val) // Update for a single version
{
	if (left <= i && right >= i)
	{
		if (node == nullptr)
			node = new Node(val);

		if (left == right)
			return new Node(node->LeftChild, node->RightChild, val);

		Node *goLeft = insert(node->LeftChild, left, mid, i, val);
		Node *goRight = insert(node->RightChild, mid + 1, right, i, val);
		Node *res = new Node(goLeft, goRight);
		return merge(goLeft, goRight, 1, res);
	}
	return node;
}

ll query(Node *Current, int left, int right, int k)
{
	if (left == right)
		return left;
	Current->createChildren();
	ll leftSum = Current->LeftChild->Value;
	if (k <= leftSum)
		return query(Current->LeftChild, left, mid, k);
	else
		return query(Current->RightChild, mid + 1, right, k - leftSum);
}

// Interface

Node *insert(Node *Current, int i, ll val)
{
	return insert(Current, 0, N, i, val);
}

ll query(Node *Current, int k)
{
	ll ans = query(Current, 0, N, k);
	return ans;
}

#undef mid

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> vc(N);
		map<int, vector<int>> mp;
		for (int i{}; i < N; i++)
		{
			cin >> vc[i];
			mp[vc[i]].push_back(i);
		}

		Versions[100001] = new Node(0);
		for (int i = 100000; i >= 1; i--)
		{
			Versions[i] = Versions[i + 1];
			if (mp.count(i))
				for (const int &ind : mp[i])
					Versions[i] = insert(Versions[i], ind, 1);
		}

		while (Q--)
		{
			int L, k;
			cin >> L >> k;
			cout << vc[query(Versions[L], k)] << endl;
		}
	}
	return 0;
}
