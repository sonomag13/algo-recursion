// LeetCode 437. Path Sum III
// Medium

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return _hasPathSum(root, targetSum);
        
    }
    
private: 
    
    bool _hasPathSum(TreeNode * root, int target) {
        
        if (!root) {
            return false; 
        }
        
        target -= root->val;                
        
        if (!root->left && !root->right && target == 0) {
            return true; 
        }
        
        return _hasPathSum(root->left, target) || _hasPathSum(root->right, target); 
                
    }
    
    
};