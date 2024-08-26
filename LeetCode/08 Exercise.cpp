* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode*left=head;
        ListNode*right=head;
        for(int i=0;i<k-1 &&left !=nullptr;i++){
            left=left->next;
        }
        int leftValue=0;
        if(left){
         leftValue=left->val;
        }
        else {
            return head;
        }


        int size=0;
        ListNode*current=head;
        while(current){
            size++;
            current=current->next;
        }
        int rightSize=size-k;
        for(int i=0;i<rightSize&& right!=nullptr;i++){
            right=right->next;
        }
        int rightValue=0;
        if(right){
         rightValue=right->val;
        }
        else {
            return head;
        }
        left->val=rightValue;
        right->val=leftValue;
        return head;
    }

};
---------------------------------------------ANOTHER SOLUTION------------------------------------------------------------------------------------------------------
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = head;
        ListNode* current = head;

        for (int i = 0; i < k - 1; i++) {
            left = left->next;
        }

        current = left;
        while (current->next) {
            current = current->next;
            right = right->next;
        }

        int temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};
