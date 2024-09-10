#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *next;
    int data;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Node* temp = new Node(value);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void reverseAndPrint() {
        vector<int> elements;
        Node* current = head;
        while (current != nullptr) {
            elements.push_back(current->data);
            current = current->next;
        }
        // Print elements in reverse order
        for (int i = elements.size() - 1; i >= 0; --i) {
            cout << elements[i];
        }
        cout << endl;
    }

    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2) {
    LinkedList result;
    Node* p1 = num1.head;
    Node* p2 = num2.head;
    int carry = 0;

    while (p1 != nullptr || p2 != nullptr || carry != 0) {
        int sum = carry;
        if (p1 != nullptr) {
            sum += p1->data;
            p1 = p1->next;
        }
        if (p2 != nullptr) {
            sum += p2->data;
            p2 = p2->next;
        }
        carry = sum / 10;
        result.add(sum % 10);
    }

    result.reverseAndPrint();  
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; ++i) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; ++i) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}
