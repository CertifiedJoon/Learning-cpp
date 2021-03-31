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

void PrintInorder(BinaryNode* node) {
	BinaryNode* root = node;
	
	while(root) {
		if (root->left) {
			BinaryNode* prev = root->left;
			
			while(prev->right && prev->right != root)
				prev = prev->right;
			
			if (!prev->right){
				prev->right = root;
				root = root->left;
			} else if (prev->right == root) {
				std::cout << root->data << " ";
				prev->right = nullptr;
				root = root -> right;
			}
		} else {
			std::cout << root->data << " ";
			root = root->right;
		}
	}
	
	std::cout << std::endl;
}

Bool isBST(BinaryNode *node) {
	if (!node) return true;
	
	if (node->left && node->data < node->left->data) return false;
	if (node->right && node->data > node->right->data) return false;
	
	return isBST(node->left) && isBST(node->right);
}

BinaryNode* DeleteValue(BinaryNode* node, int value) {
	if (node == nullptr) return nullptr;
	
	if (value < node->data)
		node->left = DeleteValue(node->left, value);
	else if (value > node->data)
		node->right = DeleteValue(node->right, value);
	else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		} else if (node->left == nullptr) {
			BinaryNode* temp = node;
			node = node->right;
			delete temp;
		} else if (node->right = nullptr) {
			BinaryNode* temp = node;
			node = node->left;
			delete temp;
		} else {
			BinaryNode* temp = GetMinNode(node->right);
			node->data = temp->data;
			node->right = DeleteValue(node->right, temp->data;)
		}
	}
	return node;
}

BinaryNode* GetSuccessor(BinaryNode* node, int value) {
	if (node == nullptr) return node;
	
	BinaryNode* target_node = node;
	while (target_node->data != value) {
		if (value < target_node->data) {
			target_node = target_node->left;
		} else if (value > target_node->data) {
			target_node = target_node->right;
		}
	}
	
	if (target_node->right != nullptr) {
		return GetMinNode(target_node->right);
	} else {
		BinaryNode* successor = nullptr;
		BinaryNode* ancestor = node;
		
		while (ancestor != nullptr) {
			if (value < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			} else {
				ancestor = ancestor->right;
			}
		}
	}
	
	return successor;
}














