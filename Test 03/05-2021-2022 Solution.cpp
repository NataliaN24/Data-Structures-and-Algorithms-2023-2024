#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }
    void insert(int value) {
        root = insert(root, value);
    }

    void printSpecific(int dividedBy) {
        print(root, dividedBy);
    }

private:



    Node* root;
    void print(Node* root, int dividedBy) {
        if (root == nullptr) {
            return;
        }
        if (root->left!=nullptr || root->right!=nullptr) {
            if (root->value % dividedBy == 0) {
                cout << root->value<<" ";
            }
        }
        print(root->left, dividedBy);
        print(root->right, dividedBy);
    }


    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            
        }
        return curNode;
    }
};
int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    int dividedBy;
    cin >> dividedBy;
    tree.printSpecific(dividedBy);
    return 0;
}
