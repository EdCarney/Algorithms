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

void rotateCW(struct tnode* rootNode);

void rotateCCW(struct tnode* rootNode);

void rotateCW(struct tnode* rootNode) {
    struct tnode* childNode = rootNode->lnode;

    childNode->parent = rootNode->parent;
    if (rootNode->parent) {
        if (rootNode->parent->lnode == rootNode)
            rootNode->parent->lnode = childNode;
        else
            rootNode->parent->rnode = childNode;
    }

    rootNode->lnode = childNode->rnode;
    if (childNode->rnode)
        childNode->rnode->parent = rootNode;

    childNode->parent = rootNode->parent;
    rootNode->parent = childNode;
    childNode->rnode = rootNode;
}

void rotateCCW(struct tnode* rootNode) {
    struct tnode* childNode = rootNode->rnode;

    childNode->parent = rootNode->parent;
    if (rootNode->parent) {
        if (rootNode->parent->lnode == rootNode)
            rootNode->parent->lnode = childNode;
        else
            rootNode->parent->rnode = childNode;
    }

    rootNode->rnode = childNode->lnode;
    if (childNode->lnode)
        childNode->lnode->parent = rootNode;

    childNode->parent = rootNode->parent;
    rootNode->parent = childNode;
    childNode->lnode = rootNode;
}

struct tnode* treapInsert(struct tnode* rootNode, struct tnode* newNode) {

    if (!rootNode)
        return newNode;

    if (newNode->key < rootNode->key) {
        rootNode->lnode = treapInsert(rootNode->lnode, newNode);
        if (rootNode->priority < rootNode->lnode->priority)
            rotateCW(rootNode);
    }
    else {
        rootNode->rnode = treapInsert(rootNode->rnode, newNode);
        if (rootNode->priority < rootNode->rnode->priority)
            rotateCCW(rootNode);
    }

    return rootNode;



    struct tnode *x = rootNode, *y = NULL;

    // first, insert the node based on the key

    // find empty spot for the node
    while(x) {
        y = x; // trailing pointer
        if (newNode->key < x->key)
            x = x->lnode;
        else
            x = x->rnode;
    }

    // set the new node parent
    newNode->parent = y;

    // add the node
    if (newNode->key < y->key)
        y->lnode = newNode;
    else
        y->rnode = newNode;

    // now, need to max-treapify
    while(y) {
        maxTreapify(y);
        y = y->parent;
    }

    return rootNode;
}

void maxTreapify(struct tnode* parentNode) {
    struct tnode* largestNode = parentNode;

    if (parentNode->lnode->priority > largestNode->priority)
        largestNode = parentNode->lnode;
    
    if (parentNode->rnode->priority > largestNode->priority)
        largestNode = parentNode->rnode;

}