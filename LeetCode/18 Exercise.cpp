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
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
        {
            return false;
        }
        unordered_set<int>seen;
        return find(root,k,seen);

    }
    private:
    bool find(TreeNode*node,int k,unordered_set<int>&seen){
        if(node==nullptr){
            return false;
        }
        if(seen.find(k- node->val)!=seen.end()){
            return true;
        }
        seen.insert(node->val);
        return find(node->left,k,seen)||find(node->right,k,seen);
    }
};
