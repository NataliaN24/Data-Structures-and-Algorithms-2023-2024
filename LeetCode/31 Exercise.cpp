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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
         pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
     return !s.empty();
    }
    private:
    stack<TreeNode*> s;
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
