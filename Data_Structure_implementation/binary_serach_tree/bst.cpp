#include "bst.h"

BinaryNode* GetNewNode(int value) {
	BinaryNode *a = new BinaryNode();
	a->data = value;
	a->left = a->right = nullptr;
	
	return a;
}

bool has(BinaryNode *node, int value) {
	BinaryNode *root = node;
	
	while(root) {
		if (root->left){
			BinaryNode *prev = root->left;
			while(prev->right && prev->right != root)
				prev = prev->right;
			
			if (prev->right == nullptr){
				prev->right = root;
				root = root->left;
			} else if (prev->right == root) {
				if (root->data == value) return true;
				prev->right = nullptr;
				root = root->right
			}
		} else {
			if (root->data == value) return true;
			root = root->right
		}
	}
	
	return false;
}

void DeleteTree(BinaryNode* node) {
	BinaryNode *root = node;
	while(root) {
		if (root->left){
			BinaryNode *prev = root->left;
			while(prev->right && prev->right != root)
				prev = prev->right;
			
			if (prev->right == nullptr){
				prev->right = root;
				root = root->left;
			} else if (prev->right == root) {
				BinaryNode *temp = root;
				prev->right = nullptr;
				root = root->right;
				delete temp;
			}
		} else {
			BinaryNode *temp = root;
			root = root->right;
			delete temp;
		}
	}
	delete node;
}

int GetMin(BinaryNode* node) {
	BinaryNode *root = node;
	
	while(root->left) 
		root = root->left;
	
	return root->data;
}

int GetMax(BinaryNode* node) {
	BinaryNode *root = node;
	
	while(root->right)
		root = root->right;
	
	return root->data;
}

int GetHeight(BinaryNode* node) {
	if (node == nullptr)
		return 0;
	
	return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

void PrintBFS(BinaryNode* node) {
	std::queue<BinaryNode*> node_queue;
	
	BinaryNode* current;
	
	node_queue.push(node);
	
	
	while (!node_queue.empty()) {
		current = node_queue.front();
		node_queue.pop();
		
		if (current != nullptr) {
			std::cout << current->data << " ";
			
			if (current->left != nullptr) node_queue.push(current->left);
			if (current->right != nullptr) node_queue.push(current->right);
		}
	}
}


