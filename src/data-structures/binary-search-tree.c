#include <stdlib.h>
#include <stdio.h>
#include "binary-search-tree.h"

struct bstNode* initializeBstNode() {
    struct bstNode* newNode = malloc(sizeof(struct bstNode));
    if (!newNode) {
        perror("Malloc failed.");
        exit(1);
    }
    setBstNodeDefaults(newNode);
    return newNode;
}

void setBstNodeDefaults(struct bstNode* node) {
    node->key = 0;
    node->lnode = NULL;
    node->rnode = NULL;
    node->parent = NULL;
}

struct bstNode* constructBst(double array[], int numElements) {
    // set root node (this will be returned)
    struct bstNode* rootNode = initializeBstNode();
    rootNode->key = array[0];

    // populate rest of the tree
    struct bstNode *x, *y;
    for (int i = 1; i < numElements; ++i) {
        x = rootNode;

        // find empty spot for the node
        while (x) {
            y = x; // trailing pointer
            if (array[i] < x->key)
                x = x->lnode;
            else
                x = x->rnode;
        }

        // add the node
        if (array[i] < y->key) {
            y->lnode = initializeBstNode();
            y->lnode->key = array[i];
            y->lnode->parent = y->lnode;
        }
        else {
            y->rnode = initializeBstNode();
            y->rnode->key = array[i];
            y->rnode->parent = y->rnode;
        }
    }

    return rootNode;
}

void inOrderTreeWalk(struct bstNode* rootNode) {
    if (!rootNode)
        return;

    inOrderTreeWalk(rootNode->lnode);
    printf("%.1f, ", rootNode->key);
    inOrderTreeWalk(rootNode->rnode);
}

struct bstNode* treeSearch(struct bstNode* rootNode, double key) {
    if (!rootNode || key == rootNode->key) {
        return rootNode;
    }
    if (key < rootNode->key)
        return treeSearch(rootNode->lnode, key);
    else
        return treeSearch(rootNode->rnode, key);
}

struct bstNode* treeSearchIterative(struct bstNode* rootNode, double value) {
    while (rootNode && rootNode->key != value) {
        if (value < rootNode->key)
            rootNode = rootNode->lnode;
        else
            rootNode = rootNode->rnode;
    }
    return rootNode;
}

struct bstNode* treeMinimum(struct bstNode* rootNode) {
    if (rootNode->lnode)
        return treeMinimum(rootNode->lnode);
    return rootNode;
}

struct bstNode* treeMaximum(struct bstNode* rootNode) {
    if (rootNode->rnode)
        return treeMaximum(rootNode->rnode);
    return rootNode;
}

struct bstNode* treeSuccessor(struct bstNode* rootNode) {
    // if there is a right subtree, then the successor
    // is the min in that subtree
    if (rootNode->rnode)
        return treeMinimum(rootNode->rnode);
    // otherwise, the successor is the first left-parent
    // of the rootNode that is a left-child
    struct bstNode* parentNode = rootNode->parent;
    while (parentNode && rootNode == parentNode->rnode) {
        rootNode = parentNode;
        parentNode = parentNode->parent;
    }
    return parentNode;
}

struct bstNode* treePredecessor(struct bstNode* rootNode) {
    // if there is a left tree, then the predecessor
    // is the max in that tree
    if (rootNode->lnode)
        return treeMaximum(rootNode->lnode);
    // otherwise, the predecessor is the first right-parent
    // of the rootNode that is a right-child
    struct bstNode* parentNode = rootNode->parent;
    while (parentNode && rootNode == parentNode->lnode) {
        rootNode = parentNode;
        parentNode = parentNode->parent;
    }
    return parentNode;
}