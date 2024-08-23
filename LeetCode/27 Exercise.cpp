class Solution {
public:
TreeNode*helperFunction(vector<int>&arr,int&index,int bound)
{
    if(index>=arr.size()|| arr[index]>bound)
    {
        return nullptr;
    }
    TreeNode*root=new TreeNode(arr[index++]);
    root->left=helperFunction(arr,index,root->val);
    root->right=helperFunction(arr,index,bound);
    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helperFunction(preorder,index,INT_MAX);   
    }
};
-------------------------------------------------ANOTHER SOLUTION ---------------------------------------------------------------------------------------------------
  class Solution {

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = nullptr;
           
            while (!s.empty() && preorder[i] > s.top()->val) {
                node = s.top();
                s.pop();
            }
            
            if (node) {
                node->right = new TreeNode(preorder[i]);
                s.push(node->right);
            } else {
        
                s.top()->left = new TreeNode(preorder[i]);
                s.push(s.top()->left);
            }
        }
        return root;
    }
};
