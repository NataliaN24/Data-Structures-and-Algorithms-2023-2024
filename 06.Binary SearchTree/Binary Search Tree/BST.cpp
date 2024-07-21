#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int value)
	{
		data = value;
		left = right = nullptr;
	}
};

class BST
{
private:
	Node* root;

	Node* insert(Node* current, int value)
	{
		if (current == nullptr)
		{
			return new Node(value);
		}
		if (value < current->data)
		{
			current->left = insert(current->left, value);
		}
		else
		{
			current->right = insert(current->right, value);
		}
		return current;
	}
	void inorder(Node* currentNode)
	{
		if (currentNode == nullptr)
		{
			return;
		}
		inorder(currentNode->left);
		std::cout << currentNode->data << " ";
		inorder(currentNode->right);
	}
	bool search(Node* node, int value)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->data == value)
		{
			return true;
		}
		if (value < node->data)
		{
			return search(node->left, value);
		}
		else
		{
			return search(node->right, value);
		}
	}
	Node* findMin(Node* node)
	{
		while (node && node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
	Node* remove(Node* node, int value)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (value < node->data)
		{
			node->left = remove(node->left, value);
		}
		else if (value > node->data)
		{
			node->right = remove(node->right, value);
		}
		else
		{
			if (node->left == nullptr)
			{
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}
			Node* temp = findMin(node->right);
			node->data = temp->data;
			node->right = remove(node->right, temp->data);
		}
		return node;
	}
public:
	BST()
	{
		root = nullptr;
	}
	void insert(int value)
	{
		root = insert(root,value);
	}
	bool search(int value)
	{
		return search(root,value);
	}
	void remove(int value)
	{
		root = remove(root, value);
	}
	void inorder()
	{
		inorder(root);
	std::cout <<std:: endl;
	}
};
int main() {
	BST tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
	tree.insert(4);
	tree.insert(6);
	tree.insert(8);

	std::cout << "Inorder traversal: ";
	tree.inorder();

	std::cout << "Search for 4: " << (tree.search(4) ? "Found" : "Not Found") << std::endl;
	std::cout << "Search for 10: " << (tree.search(10) ? "Found" : "Not Found") << std::endl;

	tree.remove(4);
	std::cout << "Inorder traversal after removing 4: ";
	tree.inorder();

	tree.remove(5);
	std::cout << "Inorder traversal after removing 5: ";
	tree.inorder();

	return 0;
}