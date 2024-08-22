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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        int sum=0;
        ListNode*current=head->next;
        ListNode*newhead=nullptr;
        ListNode*tail=nullptr;
        
        while(current){
            if(current->val!=0){
                sum+=current->val;
            }
            else{
               ListNode* newNode=new ListNode(sum);
               if(newhead==nullptr){
                newhead=newNode;
                tail=newNode;
               }
               else{
                tail->next=newNode;
                tail=tail->next;
               }
                sum=0;
            }
            current=current->next;

        }
        return newhead;
    }
};
