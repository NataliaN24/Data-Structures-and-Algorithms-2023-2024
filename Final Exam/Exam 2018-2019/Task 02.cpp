#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int d) :data(d) {}

};
Node* root = nullptr;

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
void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
Node* findMin(Node* node)
{
    while (node && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}
Node* remove(Node* root, int value)
{
    if (root == nullptr)
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = remove(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = remove(root->right, value);
    }
    else {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}
void print_odd_layers(Node* root,int level=1)
{
    if (root == nullptr) {
        return;
    }
   
        if(level%2!=0){
    cout << root->data << " ";
        }
    
    print_odd_layers(root->left,level+1);
    print_odd_layers(root->right,level+1);
    

}

int main()
{
    int n, value;
    cin >> n;
    string option;
    for (int i = 0; i < n; i++) {
        cin >> option;
        if (option == "print") {
            printTree(root);
        }
        else if (option == "add") {
            cin >> value;
           root= add(root,value);
        }
        else if (option == "remove") {
            cin >> value;
            root=remove(root, value);
        }
        else if (option == "print_odd_layers")
        {
            print_odd_layers(root);
        }
    }
}


