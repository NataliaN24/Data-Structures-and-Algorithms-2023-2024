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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==nullptr|| left>=right){
            return head;
        }
        
        ListNode*current=head;
        ListNode*prev=nullptr;
        for(int i=1;i<left && current!=nullptr;i++){
            prev=current;
            current=current->next;
        }
        ListNode*tail=current;
        ListNode*connectionPoint=prev;
        ListNode*nextNode=nullptr;

        for(int i=left;i<=right;i++){
            nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        if(connectionPoint!=nullptr){
            connectionPoint->next=prev;
        }else{
            head=prev;
        }
        tail->next=current;
        return head;

    }
};
