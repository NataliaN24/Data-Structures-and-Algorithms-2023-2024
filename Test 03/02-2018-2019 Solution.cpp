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

    void deletePenultimateAndPrint() {
        remove(root);
        print(root);
    }

private:

    //you can write helper functions if needed
    Node* root;

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
    bool isLeaf(Node* root) {
        return  root!=nullptr&& root->left == nullptr && root->right == nullptr;
    }

    void remove(Node*& root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }

        if (root->left != nullptr && root->right != nullptr) {
            if (isLeaf(root->left) && isLeaf(root->right)) {
                Node* temp = root->right;
                root->right->left = root->left;
                delete root;
                root = temp;
            }
             remove(root->left);
            remove(root->right);

        }

        else  if ( root->right == NULL) {
            if(isLeaf(root->left) ){
            Node* temp = root->left;
            delete root;
            root = temp;
            }
            remove(root->left);

        }
        else if (root->left == NULL) {
            if(isLeaf(root->right) ){
            Node* temp = root->right;
            delete root;
            root = temp;
            }
            remove(root->right);
        }


    }

    void print(Node*& node) {
        if (node == nullptr) {
            return;
        }
        print(node->left);
        cout << node->value << " ";
        print(node->right);
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
    tree.deletePenultimateAndPrint();
    return 0;
}
