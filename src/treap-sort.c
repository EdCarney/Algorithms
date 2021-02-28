#include <stdlib.h>


struct tnode {
    char key;
    int priority;
    struct tnode* parent;
    struct tnode* lnode;
    struct tnode* rnode;
};

// Inserts a new node into a treap.
// Returns a pointer to the root node of the treap.
struct tnode* treapInsert(struct tnode* rootNode, struct tnode* newNode);

struct tnode* treapInsert(struct tnode* rootNode, struct tnode* newNode) {

    // if root node is null, no treap exists yet
    if (rootNode == NULL)
        return newNode;

    

    return rootNode;
}