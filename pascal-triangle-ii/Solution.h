// LeetCode 119. Pascal's Triangle II
// Easy

#include <vector>

using namespace std; 

// using recursion
class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        return _getRow(rowIndex);        
    }
    
private:
    vector<int> _getRow(int rowIdx) {
        
        if (rowIdx == 0) {
            return vector<int>{1}; 
        }        
        
        vector<int> above = _getRow(rowIdx - 1); 
        vector<int> curr{1}; 
        
        for (int i = 1; i < above.size(); i++) {
            curr.push_back(above[i - 1] + above[i]);
        }
        
        curr.push_back(1);
        
        return curr; 
        
    }
}; 