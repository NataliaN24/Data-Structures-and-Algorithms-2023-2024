#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next; // Store next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;       // Move to the next node
        }
        
        return prev; // prev will be the new head after the loop
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to append a new node at the end of the list
void append(ListNode** head_ref, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    ListNode* last = *head_ref;
    if (!*head_ref) {
        *head_ref = new_node;
        return;
    }
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
}

// Helper function to delete the entire linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = nullptr;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Clean up memory
    deleteList(reversedHead);

    return 0;
}
