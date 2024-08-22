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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      
        vector<int>arr;
        inorder(root1,arr);
         inorder(root2,arr);
         std::sort(arr.begin(),arr.end());
         return arr;


    }
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==nullptr){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
         inorder(root->right,arr);
    }

};
