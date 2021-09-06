// LeetCode 124. Binary Tree Maximum Path Sum
// Hard

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
    int maxPathSum(TreeNode* root) {
        
        _maxPathSum(root);
        
        return maxSum;
    }
    
private:
    int maxSum{INT_MIN};
    
    int _maxPathSum(TreeNode * root) {
        
        // base case
        if (!root) {
            return 0; 
        }
        
        int currVal{root->val}; 
        
        int leftSum = max(0, _maxPathSum(root->left));                        
        int rightSum = max(0, _maxPathSum(root->right));
        
        
        int localMax{currVal + leftSum + rightSum};                 
        
        this->maxSum = max(this->maxSum, localMax); 
        
        // notice that we can only return either the left sum or rigt sum for a path
        // if return curr val + left sum + right sum, it is already a path
        return currVal + max(leftSum, rightSum); 
        
    }
        
};