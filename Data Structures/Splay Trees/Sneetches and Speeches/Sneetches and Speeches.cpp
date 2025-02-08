#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class SplayTree
{
public:
	ll size = 1;
	ll value;
	// For consecutive counting
	ll pref0, pref1; // Length of prefix of 0s and 1s
	ll suf0, suf1;	 // Length of suffix of 0s and 1s
	ll ans0, ans1;	 // Maximum consecutive 0s and 1s
	ll c0, c1;		 // Count of 0s and 1s
	// Lazy propagation flags
	bool flipProp = false;
	bool reverseProp = false;
	bool assignProp = false; // New flag for assignment
	ll assignValue = 0;		 // Value to assign
	SplayTree *left = nullptr;
	SplayTree *right = nullptr;
	SplayTree *parent = nullptr;

	// Constructor
	SplayTree(const ll &value = 0) : value(value)
	{
		if (value == 1)
		{
			pref0 = suf0 = ans0 = c0 = 0;
			pref1 = suf1 = ans1 = c1 = 1;
		}
		else // Value is 0
		{
			pref1 = suf1 = ans1 = c1 = 0;
			pref0 = suf0 = ans0 = c0 = 1;
		}
	}

	// Here we merge the nodes in INORDER behaviour (left -> parent -> right)
	void update()
	{
		size = 1;
		c0 = (value == 0);
		c1 = (value == 1);
		if (left != nullptr)
		{
			size += left->size;
			c0 += left->c0;
			c1 += left->c1;
		}
		if (right != nullptr)
		{
			size += right->size;
			c0 += right->c0;
			c1 += right->c1;
		}
		ll lp0 = 0, ls0 = 0, la0 = 0, lp1 = 0, ls1 = 0, la1 = 0;
		if (left)
		{
			lp0 = left->pref0;
			ls0 = left->suf0;
			la0 = left->ans0;
			lp1 = left->pref1;
			ls1 = left->suf1;
			la1 = left->ans1;
		}

		ll rp0 = 0, rs0 = 0, ra0 = 0, rp1 = 0, rs1 = 0, ra1 = 0;
		if (right)
		{
			rp0 = right->pref0;
			rs0 = right->suf0;
			ra0 = right->ans0;
			rp1 = right->pref1;
			rs1 = right->suf1;
			ra1 = right->ans1;
		}

		if (value == 1)
		{
			pref1 = lp1 == (left ? left->size : 0) ? lp1 + 1 + rp1 : lp1;
			suf1 = rs1 == (right ? right->size : 0) ? rs1 + 1 + ls1 : rs1;
			ans1 = max({la1, ra1, ls1 + 1 + rp1});
			pref0 = lp0;
			suf0 = rs0;
			ans0 = max(la0, ra0);
		}
		else
		{
			pref0 = lp0 == (left ? left->size : 0) ? lp0 + 1 + rp0 : lp0;
			suf0 = rs0 == (right ? right->size : 0) ? rs0 + 1 + ls0 : rs0;
			ans0 = max({la0, ra0, ls0 + 1 + rp0});
			pref1 = lp1;
			suf1 = rs1;
			ans1 = max(la1, ra1);
		}
	}

	inline void applyReverse()
	{
		reverseProp ^= 1;

		swap(left, right);
		swap(pref0, suf0);
		swap(pref1, suf1);
	}
	// For lazy propagation
	inline void applyUpdate(ll x)
	{
		if (x == -1) // XOR with 1
		{
			value ^= 1;
			flipProp ^= true;
			swap(pref0, pref1);
			swap(suf0, suf1);
			swap(ans0, ans1);
			swap(c0, c1);
		}
		else // Assignment
		{
			value = x;
			flipProp = false;	 // Assignment cancels XOR
			reverseProp = false; // Assignment cancels reverse
			assignProp = true;
			assignValue = x;
			if (x == 1)
			{
				pref0 = suf0 = ans0 = c0 = 0;
				pref1 = suf1 = ans1 = c1 = size;
			}
			else
			{
				pref1 = suf1 = ans1 = c1 = 0;
				pref0 = suf0 = ans0 = c0 = size;
			}
		}
	}

	void push()
	{
		// Handle assignments first as they override everything
		if (assignProp)
		{
			if (left != nullptr)
				left->applyUpdate(assignValue);
			if (right != nullptr)
				right->applyUpdate(assignValue);

			assignProp = false;
		}

		if (flipProp)
		{
			if (left != nullptr)
				left->applyUpdate(-1);
			if (right != nullptr)
				right->applyUpdate(-1);

			flipProp = false;
		}
		if (reverseProp)
		{
			if (left != nullptr)
				left->applyReverse();
			if (right != nullptr)
				right->applyReverse();

			reverseProp = false;
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
ll lazyValue;

// Template function
template <void Process(SplayTree *x)>
tuple<ll> apply(SplayTree *tree, int L, int R)
{
	// Split into three parts: [1, L - 1], [L, R], [R + 1, end]
	auto [leftPart, middle] = SplayTree::split(tree, L - 1);
	auto [seg, rightPart] = SplayTree::split(middle, R - L + 1);
	tuple<ll> res;
	if (seg != nullptr)
	{
		res = {seg->value};
		Process(seg);
	}
	tree = SplayTree::merge(leftPart, SplayTree::merge(seg, rightPart));
	if (tree)
		tree->update(); // Ensure data is updated after merge
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

inline void lazyXor(SplayTree *x)
{
	x->applyUpdate(lazyValue);
}

inline void lazyAssignment(SplayTree *x)
{
	x->applyUpdate(lazyValue);
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
		char c;
		cin >> c;
		SplayTree *spTree = new SplayTree(c - '0');
		for (int i{2}; i <= N; i++)
		{
			cin >> c;
			spTree = SplayTree::merge(spTree, new SplayTree(c - '0'));
		}
		for (int i{}; i < Q; i++)
		{
			ll type, L, R;
			cin >> type >> L >> R;
			if (type == 1)
			{
				lazyValue = -1;
				apply<lazyXor>(spTree, L, R);
			}
			else if (type == 2)
				apply<reverse>(spTree, L, R);
			else
			{
				// We can use a useful information, the range is ONLY 0's and 1's
				// Sorting a range of 0's and 1's is just like putting all 0's in front and all 1's in the back of the range
				// First split off the range we want to sort

				// Calculate counts within this isolated segment
				auto [leftPart, middle] = SplayTree::split(spTree, L - 1);
				auto [segment, rightPart] = SplayTree::split(middle, R - L + 1);

				// Split based on count of zeros
				auto [zeros, ones] = SplayTree::split(segment, segment->c0);
				if (zeros != nullptr)
					zeros->applyUpdate(0); // Set all to 0
				if (ones != nullptr)
					ones->applyUpdate(1); // Set all to 1
				segment = SplayTree::merge(zeros, ones);
				spTree = SplayTree::merge(leftPart, SplayTree::merge(segment, rightPart));
			}
			spTree->splay();
			cout << max(spTree->ans0, spTree->ans1) << endl;
		}
	}
	return 0;
}