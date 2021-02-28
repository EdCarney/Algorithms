struct bstNode {
    int key;
    double value;
    struct bstNode* lnode;
    struct bstNode* rnode;
    struct bstNode* parent;
};

// Walks the binary search tree and prints the values out
// in order. That is, it will print the left value of the
// node, the node value, then the right value of the node.
void inOrderTreeWalk(struct bstNode* rootNode);

// Recursively searches the binary search tree rooted at
// the provided node to find the specified value. Returns
// a pointer to the node with that value, or NULL if no
// value is in the tree.
struct bstNode* treeSearch(struct bstNode* rootNode, double value);

// Iteratively searches the binary search tree rooted at
// the provided node to find the specified value. Returns
// a pointer to the node with that value, or NULL if no
// value is in the tree.
struct bstNode* treeSearchIterative(struct bstNode* rootNode, double value);

// Searches the binary search tree rooted at the provided
// node for the minimum value. Returns a pointer to the
// node in the tree with the minimum value.
struct bstNode* treeMinimum(struct bstNode* rootNode);

// Searches the binary search tree rooted at the provided
// node for the maximum value. Returns a pointer to the
// node in the tree with the maximum value.
struct bstNode* treeMaximum(struct bstNode* rootNode);