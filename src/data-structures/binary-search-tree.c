#include <stdlib.h>
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