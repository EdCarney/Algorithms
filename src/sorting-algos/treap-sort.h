// Struct for individual treap nodes.
struct tnode {
    char key;
    int priority;
    struct tnode* parent;
    struct tnode* lnode;
    struct tnode* rnode;
};

// Indicates how to assign node priorities in the treap.
enum priorityAssignment{ randPri, charBasedPri, noPri };

// Performs a clockwise rotation of the treap about the
// provided root node. This will cause the root node's
// left child to take the place of the root node and the
// root node to become the right child of its former left
// child. Any right children of the root node's left child
// become left children to the root node.
// Returns a pointer to the new root node.
struct tnode* rotateCW(struct tnode* rootNode);

// Performs a counterclockwise rotation of the treap about the
// provided root node. This will cause the root node's
// right child to take the place of the root node and the
// root node to become the left child of its former right
// child. Any left children of the root node's right child
// become right children to the root node.
// Returns a pointer to the new root node.
struct tnode* rotateCCW(struct tnode* rootNode);

// Inserts a new node into a treap and modifies treap to
// maintain the max-treap properties.
// Returns a pointer to the root node of the treap.
struct tnode* treapInsert(struct tnode* rootNode, struct tnode* newNode);

// Searches the treap for the specified key value.
// Returns true if the key value exists in the treap and
// false otherwise.
bool treapSearch(struct tnode* rootNode, char searchValue);

// Initializes a new treap node with NULL values for pointer and
// char fields and -1 for numeric fields.
// Returns a pointer to the allocated treap node.
struct tnode* initializeTreapNode();

// Initializes a new treap from a given char array. Assigns random
// priority values to each entry prior to insertion in the tree.
// Returns a pointer to the root node of the treap.
struct tnode* initializeTreapFromArray(char inputArray[], int numElements, enum priorityAssignment priAssignment);

// Retrieves a priority assignment based of the provided character.
int getCharBasedPriority(char c);