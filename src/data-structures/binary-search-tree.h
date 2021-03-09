struct bstNode {
    double key;
    struct bstNode* lnode;
    struct bstNode* rnode;
    struct bstNode* parent;
};

// Allocates memory for a new BST node and sets all values
// to their defaults (numerical as zero, pointers as NULL).
// Returns a pointer to the allocated memory.
struct bstNode* initializeBstNode();

// Allocates memory for a new BST node and sets all values
// to their defaults (numerical as zero, pointers as NULL),
// except for the key, which is set to the provided value.
// Returns a pointer to the allocated memory.
struct bstNode* initializeBstNodeWithKey(double key);

// Sets the field values for the provided node to thier
// default values (numerical as zero, pointers as NULL).
void setBstNodeDefaults(struct bstNode* node);

// Creates a BST from a provided array of doubles, using
// the double values as the BST keys. Returns a pointer
// to the root node of the resulting BST.
struct bstNode* constructBst(double array[], int numElements);

// Inserts a new node into a BST rooted at the provided
// root node.
void treeInsert(struct bstNode* rootNode, struct bstNode* newNode);

// Deletes a given node from the BST and updates child node
// pointing as needed. Need to pass a double pointer to the
// rootNode in case we need to change the node.
void treeDelete(struct bstNode** rootNode, struct bstNode* deleteNode);

// Transplants the provided toRemove and toTransplant nodes.
// The child references of the toRemove node should be updated
// prior to being used further as they will be pointing to the
// same child and parent nodes as toTransplant when returned.
void treeTransplant(struct bstNode** rootNode, struct bstNode* toRemove, struct bstNode* toTransplant);

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

// Finds the node in the tree that is printed after the
// provided node in an in-order tree walk. Returns NULL
// if the provided node has the maximum value.
struct bstNode* treeSuccessor(struct bstNode* rootNode);

// Finds the node in the tree that is printed before the
// provided node in an in-order tree walk. Returns NULL
// if the provided node has the minimum value.
struct bstNode* treePredecessor(struct bstNode* rootNode);

// Prints information for the provided node, including
// key value, parent key value, left node key value,
// and right node key value.
void printBstNode(struct bstNode* node);