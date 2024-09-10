#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
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

class BST {
    Node* root;

private:
    Node* add(Node* current, int val) {
        if (current == nullptr)
        {
            return new Node(val);
        }
        if (current->data != val) {

            if (val < current->data)
            {
                current->left = add(current->left, val);
            }
            else {
                current->right = add(current->right, val);
            }
        }
        return current;
    }
    void inorder(Node* currentNode)
    {
        if (currentNode == nullptr)
        {
            return;
        }

        std::cout << currentNode->data << " ";
        inorder(currentNode->left);
        inorder(currentNode->right);
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int value)
    {
        root = add(root, value);
    }

    void inorder()
    {
        inorder(root);

    }
};


int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (strcmp(s.c_str(), "add") == 0) {
            int val;
            cin >> val;
            tree.insert(val);
        }
        else if (strcmp(s.c_str(), "print") == 0)
        {
            tree.inorder();
        }
    }
}
