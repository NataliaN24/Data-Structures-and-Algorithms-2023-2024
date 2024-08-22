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
--------------------------------------------ANOTHER SOLUTION------------------------------------------------------------------------------------------------------
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
        vector<int>arr;
     inOrderTraversal(root, arr);
        sort(arr.begin(),arr.end());
        
         int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }

        return false;

    }
    private:
     void inOrderTraversal(TreeNode* node, std::vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left, arr);
        arr.push_back(node->val);  
        inOrderTraversal(node->right, arr);
    }

   
};
