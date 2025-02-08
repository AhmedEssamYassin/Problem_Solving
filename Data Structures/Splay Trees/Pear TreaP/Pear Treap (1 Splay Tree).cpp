#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

auto random_address = []
{ char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
std::mt19937 rnd(SEED);
#define rng(l, r) uniform_int_distribution<int64_t>(l, r)(rnd)
/*
Large Primes for hash
1000000007
10000000019
100000000003
1000000000039
10000000000037
100000000000031
1000000000000037
10000000000000061
2305843009213693951 = (1LL << 61) - 1
*/

constexpr ll mod = (1LL << 61) - 1; // Large prime,
// Takes more time, choose a smaller prime and omit mult64() for faster code but higher probability of collision
// constexpr ll mod = 1e9 + 7; // Is usually sufficient for most of the hashing problems

inline ll mult64(const ll &a, const ll &b)
{
	return __int128_t(a) * b % mod;
}
ll modPow(ll N, ll power, ll mod)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = mult64(res, N);
		N = mult64(N, N);
		power >>= 1;
	}
	return res;
}
ll b1 = rng(128, 1000000), b2 = rng(b1 + 1, 10000000);
ll b1I = modPow(b1, mod - 2, mod), b2I = modPow(b2, mod - 2, mod);
vector<ll> Pb1, Pb2, sumB1, sumB2;
void pre(ll maxSize)
{
	Pb1 = Pb2 = sumB1 = sumB2 = vector<ll>(maxSize + 1, 1);
	for (int i = 1; i <= maxSize; i++)
	{
		Pb1[i] = mult64(Pb1[i - 1], b1);
		Pb2[i] = mult64(Pb2[i - 1], b2);
		sumB1[i] = ((sumB1[i - 1] + Pb1[i]) % mod);
		sumB2[i] = ((sumB2[i - 1] + Pb2[i]) % mod);
	}
}
class Hash
{
	using pll = pair<ll, ll>;
	ll plus(const ll &x, const ll &y)
	{
		return ((__int128_t(x) + y + mod) % mod);
	}

public:
	ll size{};
	pll code{};

	explicit Hash(pair<ll, ll> x = {}, ll sz = {}) : code(std::move(x)), size(sz) {}

	Hash(const ll &x) : code({x % mod, x % mod}), size(1) {}

	Hash(const string &x) : code(), size(0)
	{
		for (const char &c : x)
			*this = *(this) + c;
	}

	void pop_front(int x)
	{
		code.first = (code.first - mult64(Pb1[--size], x) + mod) % mod;
		code.second = (code.second - mult64(Pb2[size], x) + mod) % mod;
	}

	void pop_back(int x)
	{
		code.first = mult64((code.first - x + mod), b1I);
		code.second = mult64((code.second - x + mod), b2I);
		size--;
	}
	void clear()
	{
		code = {}, size = 0;
	}
	Hash operator+(const Hash &o)
	{
		Hash ans;
		ans.code = {plus(mult64(code.first, Pb1[o.size]), o.code.first),
					plus(mult64(code.second, Pb2[o.size]), o.code.second)};
		ans.size = size + o.size;
		return ans;
	}
	friend Hash operator+(const Hash &f, const Hash &o)
	{
		return Hash({((mult64(f.code.first, Pb1[o.size]) + o.code.first) % mod),
					 ((mult64(f.code.second, Pb2[o.size]) + o.code.second) % mod)},
					f.size + o.size);
	}
	bool operator<(const Hash &o) const
	{
		if (code == o.code)
			return size < o.size;
		return code < o.code;
	}
	bool operator==(const Hash &o) const
	{
		return size == o.size && code == o.code;
	}
	bool operator!=(const Hash &o) const
	{
		return size != o.size || code != o.code;
	}
};

class SplayTree
{
public:
	ll size = 1;
	ll value;
	ll lazyAddValue = 0;
	Hash fHash;
	Hash bHash;
	bool reversed = false;
	SplayTree *left = nullptr;
	SplayTree *right = nullptr;
	SplayTree *parent = nullptr;

	// Constructor
	SplayTree(const ll &value = 0) : value(value), fHash(value), bHash(value) {}

	// Here we merge the nodes in INORDER behaviour (left -> parent -> right)
	// To merge the backward hash, make (right -> parent -> left)
	void update()
	{
		size = 1;
		fHash = value;
		bHash = value;
		if (left != nullptr)
		{
			size += left->size;
			fHash = left->fHash + fHash;
			bHash = bHash + left->bHash;
		}
		if (right != nullptr)
		{
			size += right->size;
			fHash = fHash + right->fHash;
			bHash = right->bHash + bHash;
		}
	}

	inline void applyReverse()
	{
		reversed ^= 1;
		swap(left, right);
	}
	// For lazy propagation
	inline void applyUpdate(ll x)
	{
		value += x;
		lazyAddValue += x;
	}

	void push()
	{
		if (reversed)
		{
			if (left != nullptr)
				left->applyReverse();
			if (right != nullptr)
				right->applyReverse();
			reversed = false;
		}
		if (lazyAddValue != 0)
		{
			if (left != nullptr)
				left->applyUpdate(lazyAddValue);
			if (right != nullptr)
				right->applyUpdate(lazyAddValue);
			lazyAddValue = 0;
		}
	}
	// Rotates the current node with its parent node
	// For example, if current node is left child:
	//     P          N
	//    / \   =>   / \
    //   N   C      A   P
	//  / \            / \
    // A   B          B   C
	void rotate()
	{
		if (parent == nullptr)
			return;
		SplayTree *parent = this->parent;
		SplayTree *grandparent = parent->parent;

		// Update grandparent's child pointer
		if (grandparent != nullptr)
		{
			if (grandparent->right == parent)
				grandparent->right = this;
			else
				grandparent->left = this;
		}

		// Push down lazy values before rotation
		parent->push();
		this->push();

		// Perform rotation based on whether this node is a left or right child
		if (parent->left == this)
		{ // Left child case
			parent->left = this->right;
			this->right = parent;
			if (parent->left != nullptr)
				parent->left->parent = parent;
		}
		else
		{ // Right child case
			parent->right = this->left;
			this->left = parent;
			if (parent->right != nullptr)
				parent->right->parent = parent;
		}

		// Update parent pointers
		parent->parent = this;
		this->parent = grandparent;

		// Update subtree information
		parent->update();
		this->update();
	}

	// Splays the current node to the root of the tree using a sequence of rotations
	// Uses the standard splay tree rotations:
	// - Zig: Single rotation when parent is root
	// - Zig-zig: Double rotation when both node and parent are left/right children
	// - Zig-zag: Double rotation when node and parent are opposite children
	void splay()
	{
		while (this->parent != nullptr)
		{
			SplayTree *parent = this->parent;
			SplayTree *grandparent = parent->parent;

			if (grandparent == nullptr)
			{
				// Zig case - single rotation
				this->rotate();
			}
			else
			{
				bool isParentRightChild = (grandparent->right == parent);
				bool isNodeRightChild = (parent->right == this);

				if (isParentRightChild == isNodeRightChild)
				{
					// Zig-zig case - rotate parent first, then node
					parent->rotate();
				}
				else
				{
					// Zig-zag case - rotate node twice
					this->rotate();
				}
				this->rotate();
			}
		}

		// Push down any lazy values after splaying
		this->push();
	}

	/**
	 * Traverses the tree according to the provided navigation function and returns the final node
	 * @param tree The root of the tree to search
	 * @param goTo Navigation function that returns:
	 *             1 to go left
	 *             -1 to go right
	 *             0 to stop at current node
	 * @return Pair of (final node reached, last direction taken)
	 */
	static std::pair<SplayTree *, int> find(SplayTree *&tree, const std::function<int(const SplayTree *)> &goTo)
	{
		// Handle empty tree case
		if (tree == nullptr)
			return {tree, -1};

		int direction;
		SplayTree *current = tree;

		// Navigate through the tree based on goTo function
		while (true)
		{
			// Handle lazy propagation before accessing node
			current->push();

			// Get direction from navigation function
			direction = goTo(current);

			// Stop if we've reached target node
			if (direction == 0)
				break;

			// Determine next node based on direction
			SplayTree *nextNode = (direction == 1 ? current->left : current->right);

			// Stop if we can't proceed further
			if (nextNode == nullptr)
				break;

			current = nextNode;
		}

		// Bring found node to root
		current->splay();
		return {current, direction};
	}

	/**
	 * Finds the leftmost node in the tree
	 * @param tree Root of the tree
	 * @return Pointer to the leftmost node
	 */
	static SplayTree *getLeftmost(SplayTree *&tree)
	{
		// Always navigate left until we can't anymore
		return find(tree, [&](const SplayTree *temp)
					{ return 1; })
			.first;
	}

	/**
	 * Finds the rightmost node in the tree
	 * @param tree Root of the tree
	 * @return Pointer to the rightmost node
	 */
	static SplayTree *getRightmost(SplayTree *&tree)
	{
		// Always navigate right until we can't anymore
		return find(tree, [&](const SplayTree *temp)
					{ return -1; })
			.first;
	}

	static SplayTree *merge(SplayTree *LHS, SplayTree *RHS)
	{
		if (LHS == nullptr)
			return RHS;
		if (RHS == nullptr)
			return LHS;
		SplayTree *temp = getRightmost(LHS);
		temp->right = RHS;
		RHS->parent = temp;
		temp->update();
		return temp;
	}

	/**
	 * Finds the kth element in the tree (1-based indexing)
	 * @param tree Root of the tree
	 * @param k Position to find (1-based)
	 * @return Pointer to the kth node, or nullptr if k is invalid
	 */
	static SplayTree *findKth(SplayTree *tree, int k)
	{
		// Validate input parameters
		if (!tree || k <= 0 || k > tree->size)
			return nullptr;

		SplayTree *current = tree;

		// Navigate through tree using subtree sizes
		while (current != nullptr)
		{
			// Handle lazy propagation
			current->push();

			// Calculate size of left subtree
			int leftSize = current->left ? current->left->size : 0;

			// Check if current node is kth element
			if (k == leftSize + 1)
				break;

			// Navigate left or right based on k
			if (k <= leftSize)
				current = current->left;
			else
			{
				k -= (leftSize + 1); // Adjust k for right subtree
				current = current->right;
			}
		}

		// Bring found node to root
		current->splay();
		return current;
	}

	// Splits the splay tree into two parts [1, k] and [k + 1, N]
	static std::pair<SplayTree *, SplayTree *> split(SplayTree *tree, int k)
	{
		if (tree == nullptr)
			return {nullptr, nullptr};
		if (k <= 0)
			return {nullptr, tree};
		SplayTree *middle = findKth(tree, k);
		if (middle == nullptr)
			return {nullptr, tree};
		SplayTree *R = middle->right;
		if (R != nullptr)
		{
			middle->right = nullptr;
			R->parent = nullptr;
		}
		middle->update();
		return {middle, R};
	}
	// Erase elements in range [L, R]
	SplayTree *eraseRange(SplayTree *tree, int L, int R)
	{
		if (!tree || L > R)
			return tree;

		// Split into three parts: [1, L - 1], [L, R], [R + 1, end]
		auto [leftPart, middle] = SplayTree::split(tree, L - 1);
		auto [toDelete, rightPart] = SplayTree::split(middle, R - L + 1);

		// Free the memory of deleted nodes
		freeNodes(toDelete);

		// Merge remaining parts
		return SplayTree::merge(leftPart, rightPart);
	}
	// Insert elements at position pos
	SplayTree *insert(SplayTree *tree, int pos, const vector<ll> &values)
	{
		int currentSize = (tree ? tree->size : 0);

		// Clamp position to valid range [1, size + 1]
		// Any position > size + 1 becomes size + 1
		pos = max(1, min(pos, currentSize + 1));

		auto [leftPart, rightPart] = SplayTree::split(tree, pos - 1);

		// Create new nodes for values to insert
		SplayTree *newNodes = nullptr;
		for (ll value : values)
		{
			SplayTree *newNode = new SplayTree(value);
			if (!newNodes)
				newNodes = newNode;
			else
			{
				newNodes = SplayTree::merge(newNodes, newNode);
				if (newNodes)
					newNodes->update(); // Update hash after each merge
			}
		}

		// Merge everything back together
		auto result = leftPart;
		if (newNodes)
		{
			result = SplayTree::merge(result, newNodes);
			if (result)
				result->update();
		}
		if (rightPart)
		{
			result = SplayTree::merge(result, rightPart);
			if (result)
				result->update();
		}
		return result;
	}
	void swapRange(SplayTree *&spTree, ll i, ll j, ll k, ll l)
	{
		// First split into three parts: [1, i - 1], [i, j], rest
		auto [leftPart, middle1] = SplayTree::split(spTree, i - 1);
		auto [firstRange, rightPart1] = SplayTree::split(middle1, j - i + 1);

		// From the right part, split into: [j + 1, k - 1], [k, l], rest
		auto [middle2, rightPart2] = SplayTree::split(rightPart1, k - (j + 1));
		auto [secondRange, lastPart] = SplayTree::split(rightPart2, l - k + 1);

		// Now merge in the new order:
		// [1, i - 1] + [k, l] + [j + 1, k - 1] + [i, j] + rest
		spTree = SplayTree::merge(
			leftPart,
			SplayTree::merge(
				secondRange,
				SplayTree::merge(
					middle2,
					SplayTree::merge(
						firstRange,
						lastPart))));
	}
	// Helper function to free memory of deleted nodes
	void freeNodes(SplayTree *treeNode)
	{
		if (!treeNode)
			return;
		treeNode->push(); // Ensure lazy propagation is handled
		freeNodes(treeNode->left);
		freeNodes(treeNode->right);
		if (treeNode)
			delete treeNode;
	}
	static void output(SplayTree *treeNode)
	{
		if (treeNode == nullptr)
			return;
		treeNode->push();
		// Inorder traversal
		output(treeNode->left);
		cout << treeNode->value << " ";
		output(treeNode->right);
	}
};

ll rotationT;
ll increment;

// Template function
template <void Process(SplayTree *x)>
tuple<Hash, Hash> apply(SplayTree *tree, int L, int R)
{
	// Split into three parts: [1, L - 1], [L, R], [R + 1, end]
	auto [leftPart, middle] = SplayTree::split(tree, L - 1);
	auto [seg, rightPart] = SplayTree::split(middle, R - L + 1);
	tuple<Hash, Hash> res;
	if (seg != nullptr)
	{
		res = {seg->fHash, seg->bHash};
		Process(seg);
	}
	tree = SplayTree::merge(leftPart, SplayTree::merge(seg, rightPart));
	if (tree)
		tree->update(); // Ensure hash is updated after merge
	return res;
}

inline void getSubtreeData(SplayTree *x)
{
	return;
}

inline void reverse(SplayTree *x)
{
	x->applyReverse();
}

inline void lazyUpdate(SplayTree *x)
{
	x->applyUpdate(increment);
}

inline void shift(SplayTree *x)
{
	int N = x->size;
	if (rotationT >= N)
		rotationT %= N;
	if (rotationT == 0)
		return; // No shift needed
	// Split the segment into two parts: [1, N - rotationT] and [N - rotationT + 1, N]
	auto [L, R] = SplayTree::split(x, N - rotationT);
	x = SplayTree::merge(R, L);
}

static int autoPre = (pre(7e5), 0);

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
		cin >> N >> Q;
		string str;
		cin >> str;
		SplayTree *spTree = new SplayTree(str[0] - 'a');
		for (int i{1}; i < N; i++)
			spTree = SplayTree::merge(spTree, new SplayTree(str[i] - 'a'));

		for (int i{}; i < Q; i++)
		{
			ll query, L, R, p;
			char c;
			cin >> query;
			if (query == 1)
			{
				cin >> L >> R;
				spTree = spTree->eraseRange(spTree, L, R);
			}
			else if (query == 2)
			{
				cin >> c >> p;
				spTree->insert(spTree, p, {c - 'a'});
			}
			else if (query == 3)
			{
				cin >> L >> R;

				auto rangeData = apply<getSubtreeData>(spTree, L, R);
				if (get<0>(rangeData) == get<1>(rangeData))
					cout << "yes\n";
				else
					cout << "no\n";
			}
			if (spTree != nullptr)
				spTree->splay(); // Null check before splay
		}
	}
	return 0;
}