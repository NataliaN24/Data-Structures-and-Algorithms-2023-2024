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
    ListNode* deleteMiddle(ListNode* head) {
        int size=1;
        int mid=0;
        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr){
            delete head;
            return nullptr;

        }
        ListNode*current=head;
        while(current->next!=nullptr)
        {
            size++;
            current=current->next;
            
        }
        mid=size/2;
        current=head;
        ListNode*prev=nullptr;
        for(int i=0;i<mid &&current!=nullptr ;i++)
        {
            prev=current;
            current=current->next;
        }
        if(current==nullptr)
        {
            return head;
        }
        if(current->next==nullptr)
        {
            delete current;
            prev->next=nullptr;
            return head;
        }
        ListNode*temp=current;
        prev->next=current->next;
        current=current->next;
        delete temp;
        return head;
    }
};
