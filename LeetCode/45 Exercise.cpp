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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr ||head->next==nullptr)
        {
            return head;
        }
        ListNode*current=head;
        ListNode*newhead=head->next;
        ListNode*prev=nullptr;
        while(current!=nullptr&& current->next!=nullptr){
            ListNode*nextpair=current->next->next;
            ListNode*second=current->next;
            second->next=current;
            current->next=nextpair;
            if(prev!=nullptr){
                prev->next=second;

            }
            prev=current;
            current=nextpair;
        }
        return newhead;
        
    }
};
