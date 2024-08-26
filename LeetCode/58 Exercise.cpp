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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        unordered_set<int>toremove(nums.begin(),nums.end());
        ListNode*current=head;
        ListNode*prev=nullptr;
        while(current)
        {
            if(toremove.find(current->val)!=toremove.end())
            {
                if(prev!=nullptr)
                {
                    prev->next=current->next;
                }
                else{
                    head=current->next;
                }
                ListNode*toDelete=current;
                current=current->next;
                delete toDelete;
            }
            else{
                prev=current;
                current=current->next;
            }
        }
        return head;
    }
};
