// LeetCode 113. Path Sum II
// Medium

#include <vector>

using namespace std; 

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> candidate; 
        
        _pathSum(root, candidate, targetSum); 
        
        return result; 
        
    }
    
private: 
    vector<vector<int>> result; 
    
    void _pathSum(TreeNode * root, vector<int> candidate, int target) {
        
        if (!root) {
            return; 
        }
        
        target -= root->val; 
        candidate.push_back(root->val);
        
        if (target == 0 && !root->left && !root->right) {
            result.push_back(candidate);
            return; 
        }
        
        // a new copy of candidate is passed to the next iteration
        _pathSum(root->left, candidate, target);
        _pathSum(root->right, candidate, target);
        
    }
};