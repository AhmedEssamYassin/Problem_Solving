#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class SplayTree
{
public:
    ll size = 1;
    ll value;
    ll lazyAddValue = 0;
    ll subtreeMin;
    bool reverseProp = false;
    SplayTree *left = nullptr;
    SplayTree *right = nullptr;
    SplayTree *parent = nullptr;

    // Constructor
    SplayTree(const ll &value = 0) : value(value), subtreeMin(value) {}

    // Here we merge the nodes in INORDER behaviour (left -> parent -> right)
    void update()
    {
        size = 1;
        subtreeMin = value;
        if (left != nullptr)
        {
            size += left->size;
            subtreeMin = min(subtreeMin, left->subtreeMin);
        }
        if (right != nullptr)
        {
            size += right->size;
            subtreeMin = min(subtreeMin, right->subtreeMin);
        }
    }

    inline void applyReverse()
    {
        reverseProp ^= 1;
        swap(left, right);
    }
    // For lazy propagation
    inline void applyUpdate(ll x)
    {
        value += x;
        lazyAddValue += x;
        subtreeMin += x;
    }

    void push()
    {
        if (reverseProp)
        {
            if (left != nullptr)
                left->applyReverse();
            if (right != nullptr)
                right->applyReverse();
            reverseProp = false;
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
    void swapRange(SplayTree *&spTree, ll a, ll b, ll len)
    {
        // First split into three parts: [1, a - 1], [a, a + len - 1], rest
        auto [leftPart, middle1] = SplayTree::split(spTree, a - 1);
        auto [firstRange, rightPart1] = SplayTree::split(middle1, len);

        // From the right part, split into: [a + len, b - 1], [b, b + len - 1], rest
        auto [middle2, rightPart2] = SplayTree::split(rightPart1, b - (a + len));
        auto [secondRange, lastPart] = SplayTree::split(rightPart2, len);

        // Now merge in the new order:
        // [1, a - 1] + [b, b + len - 1] + [a + len, b - 1] + [a, a + len - 1] + rest
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
    void freeNodes(SplayTree *t)
    {
        if (!t)
            return;
        t->push(); // Ensure lazy propagation is handled
        freeNodes(t->left);
        freeNodes(t->right);
        if (t)
            delete t;
    }
    static void output(SplayTree *t)
    {
        if (t == nullptr)
            return;
        t->push();
        // Inorder traversal
        output(t->left);
        cout << t->value << " ";
        output(t->right);
    }
};

ll rotationT;
ll increment;

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
        res = {seg->subtreeMin};
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

inline void lazyAdd(SplayTree *x)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, M, x;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        cin >> x;
        SplayTree *spTree = new SplayTree(x);
        for (int i{1}; i < N; i++)
        {
            cin >> x;
            spTree = SplayTree::merge(spTree, new SplayTree(x));
        }
        cin >> M;
        while (M--)
        {
            string query;
            ll x, y;
            cin >> query;
            if (query == "ADD")
            {
                ll D;
                cin >> x >> y >> D;
                increment = D;
                apply<lazyAdd>(spTree, x, y);
            }
            else if (query == "REVERSE")
            {
                cin >> x >> y;
                apply<reverse>(spTree, x, y);
            }
            else if (query == "REVOLVE")
            {
                ll T;
                cin >> x >> y >> T;
                // Revolving here is just like Right rotation
                // swap [x - 1, y - T) and [y - T, y)
                rotationT = T;
                apply<shift>(spTree, x, y);
            }
            else if (query == "INSERT")
            {
                ll P;
                cin >> x >> P;
                ++x; // To insert after position x
                spTree = spTree->insert(spTree, x, {P});
            }
            else if (query == "DELETE")
            {
                cin >> x;
                spTree = spTree->eraseRange(spTree, x, x);
            }
            else if (query == "MIN")
            {
                cin >> x >> y;
                cout << get<0>(apply<getSubtreeData>(spTree, x, y)) << endl;
            }
            spTree->splay();
        }
    }
    return 0;
}