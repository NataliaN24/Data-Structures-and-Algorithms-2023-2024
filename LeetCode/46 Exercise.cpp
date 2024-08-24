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
        ListNode*prev=NULL;


      
       while(current!=nullptr){
        bool found=false;
        while(current->next!=nullptr &&current->val==current->next->val){
            found=true;
            current=current->next;
        }
        if(found){
            current=current->next;
            if(prev!=nullptr){
                prev->next=current;

            }
            else{
                head=current;
            }
        }
        else{
            if(prev==nullptr){
                head=current;
            }
            prev=current;
            current=current->next;
        }
       }
       if(prev!=nullptr){
        prev->next=current;
       }
       return head;

    }
};
