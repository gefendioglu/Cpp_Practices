## TREES

- Trees provide moderate access/search (quicker than Linked List and slower than arrays).
- Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
- Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.
- A tree is made up of nodes (data elements) with zero, one, or several references (or pointers) to other nodes. Each node has only one other node referencing it.
- In object-oriented languages you usually define a class for the common parts of a node and one or more subclasses for the data held by a node.
- This top-level node is called the root. The root is the only node from which you have a path to every other node. The root node is inherently the start of any tree.
- Some important tree-related terms shall be known hereafter: 
  - Parent. A node that points to other nodes is the parent of those nodes. Every node except the root has one parent.
  - Child. A node is the child of any node that points to it.
  - Descendant. All the nodes that can be reached by following a path of child nodes from a particular node are the descendants of that node.
  - Ancestor. An ancestor of a node is any other node for which the node is a descendant.
  - Leaves. The leaves are nodes that do not have any children.
- Three important kinds of trees are binary trees, binary search trees, and heaps:
  - A binary tree has two children, called left and right.
  - A binary search tree is an ordered binary tree where all the nodes to the left of a node have values less than or equal to the node’s own value and all nodes to the right of a node have values greater than or equal to the node’s value. 
  - A heap is a tree in which each node is less than or equal to its children (in a **min-heap**) or greater than or equal to its children (in a **maxheap**), which means the maximum (max-heap) or minimum (min-heap) value is the root and can be accessed in constant time. 
- Many tree problems can be solved with **recursive algorithms**.
- Two fundamental orderings for traversal are **depth-first** and **breadth-first**.

## Binary Search Trees:
- The most common way to store ordered data in a tree is to use a special tree called a binary search tree (BST).
- In a BST, the value held by a node’s left child is less than or equal to its own value, and the value held by a node’s right child is greater than or equal to its value.
- The lookup operation (locating a particular node in the tree) is fast and simple. This is particularly useful for data storage.
- Binary Search Tree is a node-based binary tree data structure which has the following properties:  
  - The left subtree of a node contains only nodes with keys lesser than the node’s key.
  - The right subtree of a node contains only nodes with keys greater than the node’s key.
  - The left and right subtree each must also be a binary search tree. 
  - There must be no duplicate nodes.
- You can obtain the smallest element by following all the left children and the largest element by following all the right children. 
- The nodes can also be printed out, in order, in **O(n)** time. Given a node, you can even find the next highest node in **O(log(n))** time.
- A good way to start thinking about any problem involving a tree is to think recursively. Many tree operations can be implemented recursively.
- The algorithm to perform a lookup in a BST is as follows not recursively (if the tree value less than the searched value --> left, else --> right):
  1. Start at the root node
  2. Loop while current node is non-null
    - If the current node's value is equal to the search value
      - Return the current node
    - If the current node's value is less than the search value
      - Make the right node the current node
    - If the current node's value is greater than the search value
      - Make the left node the current node
  3. End loop

/----------------------------------------------
/----------------------------------------------

- **Example**: Binary Search Tree
  - Searching an element with class implementation and class member function
  - Searching an element is an O(log(n)) operation in a balanced binary search tree.
```cpp
#include <iostream>
#include <array>

// Binary Tree
class Node {
public:

	Node(int v) : left{ nullptr }, right{ nullptr }, value{v}{}
	
	//getter functions
	Node* getLeft() const { return left; }
	Node* getRight() const { return right; }
	int getValue() const { return value; }

	// setter functions
	void setLeft(Node* left) { this->left = left; }
	void setRight(Node* right) { this->right = right; }
	
	// tree functions
	Node* findNode(Node* root, int value);
	Node* findNode_rcrsv(Node* root, int value);

private:
	Node* left;
	Node* right;
	int value;
};

// Searching an element in a binary search tree
Node* Node::findNode(Node* root, int value) {
    // This process continues until you reach a null reference (the end of a tree)
	while (root != nullptr) {
		int curVal = root->getValue();
		if (curVal == value) break;
		if (curVal < value) {
			root = root->getRight();
		}
		else { // curVal > value
			root = root->getLeft();
		}
	}
	return root;
}

// Searching an element in a binary search tree with a recursive function
Node* Node::findNode_rcrsv(Node* root, int value) {
	if (root == nullptr) return nullptr;
	int curVal = root->getValue();
	if (curVal == value) return root;
	if (curVal < value) { 
		return findNode_rcrsv(root->getRight(), value);	
	}
	else { // curVal > value
		return findNode_rcrsv(root->getLeft(), value);
	}
}

int main()
{
	// Making a binary search tree with available values
	Node* root = new Node(5);
	Node* left = new Node(3);
	Node* right = new Node(10);

	root->setLeft(left);
	root->setRight(right);

	Node* left_left = new Node(1);
	Node* left_right = new Node(4);

	left->setLeft(left_left);
	left->setRight(left_right);

	Node* right_left = new Node(7);
	Node* right_right = new Node(12);

	right->setLeft(right_left);
	right->setRight(right_right);

	Node* searched = root->findNode(root, 7);
	std::cout << "value address: " << searched << "\n"; // value address: 0170F028
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Binary Search Tree
  - Searching an element with structure implementation and recursion function.
  - Searching an element is an O(log(n)) operation in a balanced binary search tree.

```cpp
#include <iostream>

// Binary Tree
struct node
{
	int data;
	struct node* left;
	struct node* right;
	node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

// Searching an element in binary search tree with recursion function
node* search(node* root, int key)
{
	// Base Cases: root is null or key is present at root data
	if (root == NULL || root->data == key)
		return root;

	// Key is greater than root's data 
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's data 
	return search(root->left, key);
}

int main()
{
	// Making a binary search tree with available values
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(10);
	root->left->left = new node(1);
	root->left->right = new node(4);
	root->right->left = new node(7);
	root->right->right = new node(12);

	node* searched = search(root, 7);
	std::cout << "value address: " << searched << "\n"; // value address: 00D621C8
}
```
/----------------------------------------------
/----------------------------------------------

- **Example** : Binary Search Tree
  - Deletion and insertion an element 
  - Deletion and insertion are O(log(n)) operations in binary search trees.



