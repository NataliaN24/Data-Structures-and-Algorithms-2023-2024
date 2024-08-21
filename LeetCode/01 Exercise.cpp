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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode*current=head;
        ListNode*prev=nullptr;
        while(current!=nullptr){
            prev=current;
            current=current->next;
            if(current!=nullptr &&current->val==prev->val){
                ListNode*temp=current;
                if(current->next!=nullptr){
                current=current->next;
                prev->next=current;
                delete temp;
                }
                else{
                    prev->next=nullptr;
                }
            }

        }
        return head;

    }
};
