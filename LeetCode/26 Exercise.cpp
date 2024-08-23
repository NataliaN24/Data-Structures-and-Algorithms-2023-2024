/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void inorder(TreeNode*root,vector<int>&arr){
        if(root==nullptr){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int maxvalue=0;
        unordered_map<int,int>count;
        vector<int>result;
        for(int i:arr){
            count[i]++;
            if(count[i]>maxvalue){
                maxvalue=count[i];
            }
        }
        for(auto &pair:count)
        {
            if(pair.second==maxvalue){
                result.push_back(pair.first);
            }
           
        }
        return result;
        
    }

};
