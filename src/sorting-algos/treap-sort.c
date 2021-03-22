#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "treap-sort.h"

struct tnode* rotateCW(struct tnode* rootNode) {
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

    rootNode->parent = childNode;
    childNode->rnode = rootNode;

    return childNode;
}

struct tnode* rotateCCW(struct tnode* rootNode) {
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

    rootNode->parent = childNode;
    childNode->lnode = rootNode;

    return childNode;
}

struct tnode* treapInsert(struct tnode* rootNode, struct tnode* newNode) {

    if (!rootNode)
        return newNode;

    if (newNode->key < rootNode->key) {
        rootNode->lnode = treapInsert(rootNode->lnode, newNode);
        rootNode->lnode->parent = rootNode;
        if (rootNode->priority < rootNode->lnode->priority) {
            rootNode = rotateCW(rootNode);
        }
    }
    else {
        rootNode->rnode = treapInsert(rootNode->rnode, newNode);
        rootNode->rnode->parent = rootNode;
        if (rootNode->priority < rootNode->rnode->priority) {
            rootNode = rotateCCW(rootNode);
        }
    }
    return rootNode;
}

bool treapSearch(struct tnode* rootNode, char searchValue) {
    if (!rootNode)
        return false;
    
    if (rootNode->key == searchValue)
        return true;

    if (searchValue > rootNode->key)
        return treapSearch(rootNode->rnode, searchValue);
    else
        return treapSearch(rootNode->lnode, searchValue);
}

void printTreeInfoDepthFirst(struct tnode* rootNode) {
    if (!rootNode)
        return;

    printf("---------------\n");

    printf("Parent: ");
    printTNode(rootNode);

    printf("Left Child: ");
    if (rootNode->lnode)
        printTNode(rootNode->lnode);
    else
        printf("NULL\n");

    printf("Right Child: ");
    if (rootNode->rnode)
        printTNode(rootNode->rnode);
    else
        printf("NULL\n");

    printf("---------------\n");

    printTreeInfoDepthFirst(rootNode->lnode);
    printTreeInfoDepthFirst(rootNode->rnode);
}

void printTreeKeyOrder(struct tnode* rootNode) {
    if (!rootNode)
        return;
    printTreeKeyOrder(rootNode->lnode);
    printTNode(rootNode);
    printTreeKeyOrder(rootNode->rnode);
}

void printTNode(struct tnode* nodeToPrint) {
    printf("{ key: %c, priority: %d }\n",
        nodeToPrint->key,
        nodeToPrint->priority);
}

struct tnode* initializeTreapNode() {
    struct tnode* node = malloc(sizeof(struct tnode));
    node->key = 0;
    node->lnode = NULL;
    node->rnode = NULL;
    node->parent = NULL;
    node->priority = -1;
    return node;
}

struct tnode* initializeTreapFromArray(char inputArray[], int numElements, enum priorityAssignment priAssignment) {
    struct tnode *node, *root = NULL;
    srand(time(NULL));
    for (int i = 0; i < numElements; ++i) {
        node = initializeTreapNode();
        node->key = inputArray[i];

        if (priAssignment == random)
            node->priority = rand();
        else if (priAssignment == charBased)
            node->priority = getCharBasedPriority(node->key);
        else
            node->priority = 0;

        root = treapInsert(root, node);
    }
    return root;
}

int verifyBstProperties(struct tnode* rootNode) {
    int res = 0;

    if (!rootNode)
        return res;

    if (rootNode->lnode)
        res += rootNode->key > rootNode->lnode->key ? 0 : 1;

    if (rootNode->rnode)
        res += rootNode->key < rootNode->rnode->key ? 0 : 1;

    res += verifyBstProperties(rootNode->lnode);
    res += verifyBstProperties(rootNode->rnode);

    return res;
}

int verifyMaxHeapProperties(struct tnode* rootNode) {
    int res = 0;

    if (!rootNode)
        return res;

    if (rootNode->lnode)
        res += rootNode->priority > rootNode->lnode->priority ? 0 : 1;

    if (rootNode->rnode)
        res += rootNode->priority > rootNode->rnode->priority ? 0 : 1;

    res += verifyBstProperties(rootNode->lnode);
    res += verifyBstProperties(rootNode->rnode);

    return res;
}

int getCharBasedPriority(char c) {
    if (c == 'A')
        return 24;
    else if (c == 'B')
        return 7;
    else if (c == 'C')
        return 14;
    else if (c == 'D')
        return 17;
    else if (c == 'E')
        return 26;
    else if (c == 'F')
        return 10;
    else if (c == 'G')
        return 8;
    else if (c == 'H')
        return 18;
    else if (c == 'I')
        return 22;
    else if (c == 'J')
        return 4;
    else if (c == 'K')
        return 5;
    else if (c == 'L')
        return 16;
    else if (c == 'M')
        return 13;
    else if (c == 'N')
        return 19;
    else if (c == 'O')
        return 23;
    else if (c == 'P')
        return 12;
    else if (c == 'Q')
        return 2;
    else if (c == 'R')
        return 20;
    else if (c == 'S')
        return 21;
    else if (c == 'T')
        return 25;
    else if (c == 'U')
        return 15;
    else if (c == 'V')
        return 6;
    else if (c == 'W')
        return 11;
    else if (c == 'X')
        return 3;
    else if (c == 'Y')
        return 9;
    else if (c == 'Z')
        return 1;
    else
        return 0;
}