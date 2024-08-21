#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
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
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = nullptr;
    append(&head, 4);
    append(&head, 2);
    append(&head, 10);
    append(&head, 8);
    append(&head, 3);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    std::cout << "Sorted list: ";
    printList(sortedHead);

    // Clean up memory
    deleteList(sortedHead);

    return 0;
}
