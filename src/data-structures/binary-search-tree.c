#include <stdlib.h>
#include <stdio.h>
#include "binary-search-tree.h"

void inOrderTreeWalk(struct bstNode* rootNode) {
    if (rootNode == NULL)
        return;

    inOrderTreeWalk(rootNode->lnode);
    printf("%.2f ", rootNode->value);
    inOrderTreeWalk(rootNode->rnode);
}

struct bstNode* treeSearch(struct bstNode* rootNode, double value) {
    if (rootNode == NULL || value == rootNode->value)
        return rootNode;
    
    if (value < rootNode->value)
        return treeSearch(rootNode->lnode, value);
    else
        return treeSearch(rootNode->rnode, value);
}

struct bstNode* treeSearchIterative(struct bstNode* rootNode, double value) {
    while (rootNode != NULL && rootNode->value != value) {
        if (value < rootNode->value)
            rootNode = rootNode->lnode;
        else
            rootNode = rootNode->rnode;
    }
    return rootNode;
}

struct bstNode* treeMinimum(struct bstNode* rootNode) {
    if (rootNode->lnode != NULL)
        return treeMinimum(rootNode->lnode);
    return rootNode;
}

struct bstNode* treeMaximum(struct bstNode* rootNode) {
    if (rootNode->rnode != NULL)
        return treeMaximum(rootNode->rnode);
    return rootNode;
}

struct bstNode* treeSuccessor(struct bstNode* rootNode) {
    // if there is a right subtree, then the successor
    // is the min in that subtree
    if (rootNode->rnode != NULL)
        return treeMinimum(rootNode->rnode);
    // otherwise, the successor is the first left-parent
    // of the rootNode that is a left-child
    struct bstNode* parentNode = rootNode->parent;
    while (parentNode != NULL && rootNode == parentNode->rnode) {
        rootNode = parentNode;
        parentNode = parentNode->parent;
    }
    return parentNode;
}

struct bstNode* treePredecessor(struct bstNode* rootNode) {
    // if there is a left tree, then the predecessor
    // is the max in that tree
    if (rootNode->lnode != NULL)
        return treeMaximum(rootNode->lnode);
    // otherwise, the predecessor is the first right-parent
    // of the rootNode that is a right-child
    struct bstNode* parentNode = rootNode->parent;
    while (parentNode != NULL && rootNode == parentNode->lnode) {
        rootNode = parentNode;
        parentNode = parentNode->parent;
    }
    return parentNode;
}