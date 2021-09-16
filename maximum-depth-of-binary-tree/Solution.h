// LeetCode 104. Maximum Depth of Binary Tree
// Easy

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
    int maxDepth(TreeNode* root) {
        
        if (!root) {
            return max_depth;
        }
        
        _maxDepth(root, 0); 
        
        return max_depth; 
    }
    
private: 
    int max_depth = 0;
    
    void _maxDepth(TreeNode* root, int cnt) {
        
        if (!root) {
            max_depth = max(max_depth, cnt);
            return; 
        }
        
        cnt++; 
        
        _maxDepth(root->left, cnt);
        _maxDepth(root->right, cnt);
        
    }
};