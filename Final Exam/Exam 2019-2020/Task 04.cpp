#include <iostream>
#include <vector>
using namespace std;

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

    void printLeftProfile() {
        int maxDepth = -1;  
        printLeftProfile(root, 0, maxDepth);
        cout << endl;
    }

private:
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            
        }
        return curNode;
    }

    void printLeftProfile(Node* node, int depth, int &maxDepth) {
        if (node == NULL) {
            return;
        }

   
        if (depth > maxDepth) {
            cout << node->value << " ";
            maxDepth = depth;
        }

      
        printLeftProfile(node->left, depth + 1, maxDepth);
        printLeftProfile(node->right, depth + 1, maxDepth);
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
    tree.printLeftProfile();
    return 0;
}
