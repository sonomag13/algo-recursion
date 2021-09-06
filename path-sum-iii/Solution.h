// LeetCode 437. Path Sum III
// Medium

#include <unordered_map>

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
    int pathSum(TreeNode* root, int targetSum) {
        
        this->targetSum = targetSum; 
        
        // the sum of the nodes in a path is similar to an offset for the next node
        // the the delta between the previous sum and current sum exist, then a solution is found
        unordered_map<int, int> mapSumCnt; 
        mapSumCnt.insert(make_pair<int, int>(0, 1)); 
        
        _pathSum(root, mapSumCnt, 0);
            
        return this->result; 
    }
    
private: 
    int result{0};
    int targetSum; 
    
    void _pathSum(TreeNode * root, unordered_map<int, int> mapSumCnt, int currSum) {
        
        if (!root) {
            return; 
        }
        
        currSum += root->val; 
        
        int delta{currSum - this->targetSum}; 
        
        if (mapSumCnt.find(delta) != mapSumCnt.end()) {
            this->result += mapSumCnt[delta]; 
        }
        
        if (mapSumCnt.find(currSum) != mapSumCnt.end()) {
            mapSumCnt[currSum]++; 
        }
        else {
            mapSumCnt.insert(make_pair(currSum, 1)); 
        }
        
        _pathSum(root->left, mapSumCnt, currSum);
        _pathSum(root->right, mapSumCnt, currSum);
        
        
    }
};