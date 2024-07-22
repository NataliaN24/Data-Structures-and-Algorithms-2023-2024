#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) :value(value), left(nullptr), right(nullptr) {};
};
Node* insert(Node* current, int value) {
    if (current == nullptr) {
        return new Node(value);
    }
    if (value <= current->value) {
        current->left = insert(current->left, value);
    }
    if (value > current->value) {
        current->right = insert(current->right, value);
    }
    return current;
}
int calculateSum(Node* current) {
    if (current == nullptr) {
        return 0;
    }
    int sum = 0;

    if (!current->left && !current->right) {
        if (current->value % 2 != 0) {
            sum += current->value;
        }
    }
    sum+=calculateSum(current->left);
    sum+=calculateSum(current->right);
    return sum;

}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        root = insert(root, num);
    }
    cout << calculateSum(root) << " ";
}
