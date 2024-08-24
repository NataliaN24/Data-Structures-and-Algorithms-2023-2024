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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
   
     if(head==nullptr){
        return nullptr;
     }   
       int size=1;
     ListNode*current=head;
     while(current->next!=nullptr){
        current=current->next;
        size++;
     }
     int pos=size-n;
     if(pos==0){
        ListNode*newhead=head->next;
        delete head;
        return newhead;
     }
     current=head;
     ListNode*prev=nullptr;
     
     for(int i=0;i<pos && current !=nullptr ;i++){
        prev=current;
        current=current->next;
     }
     if (current->next!=nullptr){
        prev->next=current->next;
     }
     else{
        prev->next=nullptr;
     }
     delete current;
     return head;

    }
};
