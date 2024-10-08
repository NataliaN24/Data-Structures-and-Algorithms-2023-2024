#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *leftNode;
    Node *rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
    int leftCount = 0;
    int rightCount = 0;

public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }
            return root;
        }
    }

    void countEdges(Node *root) {
        if (root == NULL) {
            return;
        }

        if (root->leftNode != NULL) {
            leftCount++;
            countEdges(root->leftNode); 
        }

        if (root->rightNode != NULL) {
            rightCount++;
            countEdges(root->rightNode); 
        }
    }

    void leftRight(Node *root) {
        countEdges(root); 
        cout << "[" << leftCount << "," << rightCount << "]" << endl;
    }
};

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leftRight(root);
    return 0;
}
