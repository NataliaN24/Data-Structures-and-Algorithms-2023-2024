#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data) :data(data), left(nullptr), right(nullptr) {};
};

Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node* current)
{
    if (current == nullptr) {
        return;
    }
    
    if (current->left && current->right)
    {
        cout << current->data<<" ";
    }
    
    inorder(current->left);
    inorder(current->right);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin>>N;
        Node* root=nullptr;
        for (int j = 0; j < N; j++) {
            int number;
            cin >> number;
           root= insert(root, number);
        }
        inorder(root);
        cout<<endl;
    }
}
