#pragma once

// Binary Search Tree Implementation using Classes
// --------------------------------------------------
// --------------------------------------------------

#ifdef BINARY_SEARCH_TREE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// --------------------------------------------------
class BinaryTree {
public:

	BinaryTree(int value) : left{ nullptr }, right{ nullptr }, value{ value }{}

	// getter functions
	BinaryTree* getLeft() const { return left; }
	BinaryTree* getRight() const { return right; }
	int getValue() const { return value; }

	// setter functions
	void setLeft(BinaryTree* left) { this->left = left; }
	void setRight(BinaryTree* right) { this->right = right; }

	// tree functions
	BinaryTree* findNode(BinaryTree* root, int value);
	BinaryTree* findNode_recursive(BinaryTree* root, int value);

private:
	BinaryTree* left;
	BinaryTree* right;
	int value;
};

// --------------------------------------------------
BinaryTree* BinaryTree::findNode(BinaryTree* root, int value){
	
	while (root != nullptr) {
		int currentValue = root->getValue();
		if (currentValue == value) 
			break;
		if (currentValue < value) 
			root = root->getRight();
		else 
			root = root->getLeft();
	}

	return root;
}

// --------------------------------------------------
BinaryTree* BinaryTree::findNode_recursive(BinaryTree* root, int value) {

	if (root == nullptr) 
		return nullptr;
	int currentValue = root->getValue();
	if (currentValue == value) 
		return root;
	if (currentValue < value) 
		return findNode_recursive(root->getRight(), value);
	else 
		return findNode_recursive(root->getLeft(), value);

}

// Test Code
// --------------------------------------------------
int main() {

	BinaryTree* root = new BinaryTree(5);
	BinaryTree* left = new BinaryTree(3);
	BinaryTree* right = new BinaryTree(10);

	root->setLeft(left);
	root->setRight(right);

	// Left Side of Root
	BinaryTree* left_left = new BinaryTree(1);
	BinaryTree* left_right = new BinaryTree(4);

	left->setLeft(left_left);
	left->setRight(left_right);

	// Right Side of Root
	BinaryTree* right_left = new BinaryTree(7);
	BinaryTree* right_right = new BinaryTree(12);

	right->setLeft(right_left);
	right->setRight(right_right);

	BinaryTree* searched = root->findNode(root, 7);
	std::cout << "value address : " << searched << "\n"; 
	// value address : 0170F028

	BinaryTree* searched_rcsv = root->findNode_recursive(root, 7);
	std::cout << "value address : " << searched_rcsv << "\n";
	// value address : 0170F028 (The same address)

}

#endif // BINARY_SEARCH_TREE


