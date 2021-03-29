#include <queue>

#ifndef BST_H
#define BST_H


namespace cj{

struct BinaryNode {
	int data;
	BinaryNode* left;
	BinaryNode* right;
};

// Returns a new node for our BST
BinaryNode* GetNewNode(int value);

// Returns true if given value is in our tree
Bool has(BinaryNode *node, int value);

//Frees memory allocated for the tree.
void DeleteTree(BSTNode* node);

//Returns the minimum value stored in the tree or -1 if tree is empty;
int GetMin(BinaryNode* node);

//Returns the maximum value stored in the tree or -1 if tree is empty;
int GetMax(BinaryNode* node);

//Return height of a stree, 0 if empty
int GetHeight(BinaryNode* node);

//Print out items in tree in breadth-first order
void PrintBFS(BinaryNode* node);

//Print out items in tree in inorder
void PrintInorder(BinaryNode* node);

//Retuns true if tree is a binary search tree;
bool IsBST(BinaryNode* node);

//Returns true if all items in the given tree are between the given values
bool IsBetween(BinaryNode* node, int lo, int hi);

//Delete a specific node from the tree
BinaryNode* DeleteValue(BinaryNode* node, int value);

//Returns the node in the tree with minimum value
BinaryNode* GetMinNode(BinaryNode* node, int value);

//Returns the in-order successor of the given value
BinaryNode* GetSuccessor(Binarynode* node, int value);

}