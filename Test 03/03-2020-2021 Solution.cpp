#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Stoyan github

struct Node {
    Node *left;
    Node *right;
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
    void print(Node*root){
        if(root==nullptr){
            return;
        }
        print(root->left);
        cout<<root->value<<" ";
        print(root->right);
    }

private:
      //you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
    bool hasChild(Node*root){
        return root->left!=nullptr ||root->right!=nullptr;
    }
    void remove(Node*&root){
        if(root==nullptr|| (root->left==nullptr &&root->right==nullptr)){
            return;
        }
        if(root->left==nullptr){
            if(!hasChild(root->right)){
                Node*temp=root->right;
                delete root;
                root=temp;
            }
            remove(root->right);
        }
        else  if(root->right==nullptr){
            if(!hasChild(root->left)){
                Node*temp=root->left;
                delete root;
                root=temp;
            }
             remove(root->left);
        }
        else{
            if(!hasChild(root->left)&&!hasChild(root->right)){
                root->right->left=root->left;
                Node*temp=root->right;
                delete root;
                root=temp;
            }
            remove(root->right);
            remove(root->left);
        }
        
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}
